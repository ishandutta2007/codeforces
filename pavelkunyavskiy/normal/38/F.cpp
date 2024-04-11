#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))
#define forn(i,n) for(int i=0;i<(n);++i)
#define ford(i,n) for(int i=(n)-1;i>=0;--i)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long long ll;
typedef long double ld;

struct node{
    node* next[26];
    node* prev[26];
    int score;
    int maxval,sum,kol;
    bool result;int sc1,sc2;
    int last;
    node(){
        score=maxval=sum=0;
        for (int i=0;i<26;i++)
            next[i]=prev[i]=0;
        sc1=sc2=-1;
        last=-1;
    }
    node* getnext(char C){
        int c=C-'a';
        if (next[c])
            return next[c];
        next[c]=new node;
        next[c]->maxval=max(maxval,c+1);
        next[c]->sum=sum+c+1;
        next[c]->kol=0;     
        next[c]->score=next[c]->maxval*next[c]->sum;        
        return next[c];
    }
};

node* root;

void add(const string& s,int pos,int num){
    int sz=s.size();
    node* v=root;
    for (int i=pos;i<sz;i++){
        v=v->getnext(s[i]);
    //  cerr<<v<<endl;
        if (v->last!=num){
            v->kol++;
            v->score++;
            v->last=num;
        }
    }       
}

void add(const string& s,int num){
    int sz=s.size();
    for (int i=0;i<sz;i++)
        add(s,i,num);
}

void calcprev(node* v,node* cv,char c){
    if (v==0 || cv==0)
        return;
    v->prev[c-'a']=cv;
    for (int i=0;i<26;i++)
        calcprev(v->next[i],cv->next[i],c);
}

const string result[2]={"First\n","Second\n"};

void getbest(bool &a,int &b,int &c,bool A,int B,int C){
    if (A!=a){
        if (A && !a){
            a=A;
            b=B;
            c=C;
        }
        return;
    }
    if (b!=B){
        if (b<B){
            a=A;
            b=B;
            c=C;            
        }
        return;
    }
    if (c>C){
        a=A;
        b=B;
        c=C;
    }   
}

void calc(node* v/*,string s*/){
    if (v->sc1!=-1)
        return;
    v->sc1=0;
    v->sc2=0;
    v->result=0;
    for (int i=0;i<26;i++)
        if (v->next[i]){
            node* tmp=v->next[i];
            calc(tmp/*,s+char(i+'a')*/);
        //      cerr<<s<<" -> "<<(s+char(i+'a'))<<endl; 

            getbest(v->result,v->sc1,v->sc2,!tmp->result,tmp->sc2,tmp->sc1);
        }           
    for (int i=0;i<26;i++)
        if (v->prev[i]){
            node* tmp=v->prev[i];
            calc(tmp/*,char(i+'a')+s*/);
        //  cerr<<s<<" -> "<<(char(i+'a')+s)<<endl; 
            getbest(v->result,v->sc1,v->sc2,!tmp->result,tmp->sc2,tmp->sc1);
        }       
    v->sc2+=v->score;
//  cerr<<s<<" "<<v->result<<" "<<v->sc1<<" "<<v->sc2<<" "<<v->score<<endl;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    root=new node;
    int n;
    cin>>n;
    string s;
    for (int i=0;i<n;i++){
        cin>>s;
        add(s,i);
//      cerr<<s<<endl;
    }
//  return 0;
    root->score=0;
    for (char i='a';i<='z';i++)
        calcprev(root,root->next[i-'a'],i);
//  return 0;
    calc(root/*,""*/);
    cout<<result[!root->result]<<root->sc1<<" "<<root->sc2<<endl;
    return 0;
}