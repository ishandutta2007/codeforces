#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <iterator>

#define mp make_pair
#define pb push_back

#ifndef LOCAL
#undef assert
#define assert(Expr) ;
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

int a,b,c;
int n,m;

char res[1000][1000];
bool used[110][110];



void eprint(){
    for (int i=0;i<2*n;i++){
        for (int j=0;j<2*m;j++)
            cerr<<((used[i/2][j/2])?(res[i][j]):('?'));
        cerr<<endl;
    }
    cerr<<endl<<endl;
}


void setval(int i,int j,int type,char l,char r=0){
    if (i>=n || j>=m) return;
//  cerr<<"SET: "<<i<<" "<<j<<" TYPE = ( "<<type<<" "<<l<<" "<<r<<" )"<<endl;
    assert(i>=0 && j>=0);
    assert(!used[i][j]);
    if (type>0){
        --c;assert(c>=0);
    }
    else if (l=='.'){
        --a;assert(a>=0);
    }
    else{
        --b;assert(b>=0);
    }                                                                        
    used[i][j]=true;
    if (type==0){
        assert(r==0);            
        assert(l=='.' || l=='#');
        res[2*i][2*j]=res[2*i+1][2*j]=res[2*i][2*j+1]=res[2*i+1][2*j+1]=l;
        return;
    }
    if (type==1){
        assert(l=='.' || l=='#');
        assert(r=='.' || r=='#');
        assert(l!=r);
        res[2*i][2*j]=res[2*i+1][2*j+1]='\\';
        res[2*i+1][2*j]=l;
        res[2*i][2*j+1]=r;
        return;
    }
    if (type==2){           
        assert(l=='.' || l=='#');
        assert(r=='.' || r=='#');
        assert(l!=r);
        res[2*i+1][2*j]=res[2*i][2*j+1]='/';
        res[2*i][2*j]=l;
        res[2*i+1][2*j+1]=r;
    }
}
                    

void colorblack(){
    if (b==0) return;
    int i,j;
    i=j=0;
    for (i=0;i<n && b;i++)
        for (j=0;j<m && b;j++)
            setval(i,j,0,'#');
    --i;                    
    if (j%2==0){
        for (int j1=0;j1<j;j1+=2){
            setval(i+1,j1,1,'.','#');
            setval(i+1,j1+1,2,'#','.');
        }   
    }   
    else {                            
        setval(i+1,0,2,'#','.');
        for (int j1=1;j1<j;j1+=2){
            setval(i+1,j1,1,'.','#');
            setval(i+1,j1+1,2,'#','.');
        }   
    }
    for (int j1=j;j1<m;j1+=2){
        setval(i,j1,2,'#','.');
        setval(i,j1+1,1,'.','#');
    }
    ++i;
}

void colorwhite(){
    for (int i=0;i<n && a;i++)
       for (int j=0;j<m && a;j++)
            if (!used[i][j])
                setval(i,j,0,'.');  
}

void colordiff(){
    int i=0;
    for (;i<n && used[i][m-1];++i);
    if (i==n) return;
    int j=m-1;
    for (;j>=0 && !used[i][j];--j);
    ++j;
    char first='.';
    char second='#';      
    for (int j1=j;j1<m;j1+=2){
        setval(i,j1,2,'.','#');
        if (j1+1<m)
            setval(i,j1+1,1,'#','.');
    }
    ++i;
    //eprint();

    if (j%2==0){
        for (;i<n;i++){
            for (int j1=0;j1<j;j1+=2){
                setval(i,j1,1,second,first);
                setval(i,j1+1,2,first,second);
            }            
            for (int j1=j;j1<m;j1+=2){
                setval(i,j1,2,second,first);
                if (j1+1<m)
                    setval(i,j1+1,1,first,second);
            }
            swap(first,second);
        }
    }
    else {
        for (;i<n;i++){
            for (int j1=0;j1<j;j1+=2){
                setval(i,j1,1,second,first);
                if (j1+1<j)
                    setval(i,j1+1,2,first,second);
            }            
            for (int j1=j;j1<m;j1+=2){
                setval(i,j1,1,first,second);
                if (j1+1<m)                     
                    setval(i,j1+1,2,second,first);    
            }
            swap(first,second);
        }
    }
}

void print(){
    assert(a==0 && b==0 && c==0);
    for (int i=0;i<2*n;i++){
        res[i][2*m]=0;
        puts(res[i]);
    }
}

              

int main(){
    cin>>n>>m>>b>>a>>c;                   
    colorblack();    
    colorwhite();  
    //eprint();
    colordiff();
    print();
    return 0;
}