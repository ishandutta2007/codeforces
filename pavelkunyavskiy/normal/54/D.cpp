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

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

string s;
string inc;
int p[1000];
int n,k;


void genp(){
    p[0]=0;
    for (int i=1;i<n;i++){
        int j=p[i-1];
        for (;j!=0 && s[j]!=s[i];j=p[j-1]);
        if (s[j]==s[i])
            ++j;
        p[i]=j;     
    }   
}

int next[110][26];

void gennext(int n,int k){
    next[n][k]=n;
    for (;next[n][k]!=0 && (next[n][k]==::n || s[next[n][k]]!='a'+k);next[n][k]=p[next[n][k]-1]);
    if (s[next[n][k]]=='a'+k)
        next[n][k]++;
//  cerr<<n<<" "<<k<<" -> "<<next[n][k]<<endl;
}

void genall(){
    genp();
    for (int i=0;i<=n;i++)
        for (int j=0;j<k;j++)
            gennext(i,j);
}

bool t[110][110];
int fromn[110][110];
int fromk[110][100];

void setval(int x,int y,int fx,int fy){
//  cerr<<"!!!"<<x<<" "<<y<<endl;
    if (t[x][y]) return;
    t[x][y]=true;
    fromn[x][y]=fx;
    fromk[x][y]=fy;
}

void gen(int x,int y){
    if (x==0 && y==0)
        return;
    assert(t[x][y]);
    gen(x-1,fromn[x][y]);
    printf("%c",char('a'+fromk[x][y]));
}




int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int m;
    cin>>m>>k>>s>>inc;
     n=s.size();
    genall();
    t[0][0]=1;
    for (int i=0;i<=m;i++){
        if (i>=n){
            if (inc[i-n]=='0')
                t[i][n]=0;
            else {
                for (int j=0;j<n;j++)
                    t[i][j]=0;
            }
        }
        if (i==m) continue;
        for (int j=0;j<=n;j++){
            if (!t[i][j]) continue;
//          cerr<<i<<" "<<j<<endl;
            for (int l=0;l<k;l++)
                setval(i+1,next[j][l],j,l);
        }
    }
    for (int i=0;i<=n;i++)
        if (t[m][i]){
            gen(m,i);
            return 0;
        }
    cout<<"No solution\n";
    return 0;
}