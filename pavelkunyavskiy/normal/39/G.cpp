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

#define div botva

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long long ll;
typedef long double ld;


const int modul=32768;

int dec(int a,int b){
    return (a-b+modul)%modul;
}

int add(int a,int b){
    return (a+b+modul)%modul;
}

int proisv(int a,int b){
    return (a*1LL*b)%modul;
}

int div(int a,int b){
    if (b==0){
        printf(",l[;,dsa");
        exit(0);
    }
    return a/b;
}


namespace arithm{
    string s;
    int n;
    enum lexem {_plus,_minus,_mull,_div,_num,_n,_end,_f};
    int f[40000];
    
    
    struct current{
        lexem lex;
        int val;
        int pos;
        void next();
        current(){
            pos=0;
        }
    };

    
    int expr();
    int mull();
    int item();
    current cur;
    
    void current::next(){
        if (pos>=s.size()){ lex=_end;return;}
        if (s[pos]=='+'){lex=_plus; ++pos;return;}
        if (s[pos]=='-'){lex=_minus;++pos;return;}
        if (s[pos]=='*'){lex=_mull;++pos;return;}
        if (s[pos]=='/'){lex=_div;++pos;return;}
        if (s[pos]=='f'){
            pos+=2;
            lex=_f;   
            return; 
        }
        if (s[pos]=='n'){
            ++pos;
            lex=_n;
            return;
        }
        string s1="";
        for (;s[pos]<='9' && s[pos]>='0';++pos)
            s1+=s[pos];
        cur.lex=_num;
        sscanf(s1.data(),"%d",&val);        
    }
    
    
    int mull(){
        if (cur.lex==_num){
            int tmp=cur.val;
            cur.next();
            return tmp;
        }
        if (cur.lex==_n){
            cur.next();
            return n;
        }
        if (cur.lex==_f){
            cur.next();
            int tmp=expr();
//          if (s[cur.pos]!=')')
//              assert(false);
            if (cur.pos<s.size() && s[cur.pos]==')')
                cur.pos++;
            cur.next();
            return f[tmp];
        }
    //  assert(false);
    }
    
    int item(){
        int a=mull();
        for (;;){
            if (cur.lex!=_mull && cur.lex!=_div) break;
            if (cur.lex==_mull){
                cur.next();
                int tmp=mull();
                a=proisv(a,tmp);
            }
            else{
                cur.next();
                int tmp=mull();
                a=div(a,tmp);           
            }           
        }
        return a;
    }
    
    int expr(){
        int a=item();
        for (;;){
            if (cur.lex!=_plus && cur.lex!=_minus) break;
            if (cur.lex==_plus){
                cur.next();
                int tmp=item();
                a=add(a,tmp);
            }
            else{
                cur.next();
                int tmp=item();
                a=dec(a,tmp);           
            }           
        }       
        return a;
    }
    
    void init(int n,const string& express){
        cur=current();
        arithm::n=n;
        s=express;
        cur.next();
    }   
}

vector<string> f;

char s1[1000],s2[1000],s3[1000];

int calc(int n){
    for (int i=0;i<f.size();i++){
        if (sscanf(f[i].data(),"return %[^;]",s1)==1){
            arithm::init(n,s1);
            return arithm::expr();
        }
        char c;
        int tmp=sscanf(f[i].data(),"if (%[^>=<] %c %[^r] return %[^;]",s1,&c,s2,s3);
        s2[strlen(s2)-1]=0;
        arithm::init(n,s1);
        int val1=arithm::expr();
        arithm::init(n,s2);
        int val2=arithm::expr();
        if (c=='=' && val1==val2){
            arithm::init(n,s3);
            int val3=arithm::expr();
            return val3;            
        }
        if (c=='<' && val1<val2){
            arithm::init(n,s3);
            int val3=arithm::expr();
            return val3;            
        }
        if (c=='>' && val1>val2){
            arithm::init(n,s3);
            int val3=arithm::expr();
            return val3;
        }
    }
    //assert(false);
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int res;
    scanf("%d ",&res);
    string func="";
    string tmp;
    while (cin>>tmp)
        func+=tmp;
    tmp=func;
    func="";
    bool q=false;
    for (int i=0;i<tmp.size();i++){
        if (tmp[i]=='}')
            q^=1;
        if (q)
            func+=tmp[i];
        if (tmp[i]=='{')
            q^=1;
    }
    for (int i=0;i<func.size();){   
        tmp="";
        for (;i<func.size() && func[i]!=';';i++){
            if (tmp.size()>0 && tmp[tmp.size()-1]!='=' || func[i]!='=')
                tmp+=func[i];
        }
        if (tmp!="")
            f.pb(tmp+';');
        i++;
    }   
    
    int ans=-1;
    
    for (int i=0;i<modul;i++){
        int val=0;
        val=calc(i);
        arithm::f[i]=val;
        if (arithm::f[i]==res)
            ans=i;
    }
            
    cout<<ans<<endl;    
    return 0;
}