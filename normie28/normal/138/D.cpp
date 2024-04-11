
// Problem : C. Knights
// Contest : Codeforces - Codeforces Round #518 (Div. 1) [Thanks, Mail.Ru!]
// URL : https://codeforces.com/contest/1067/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
#define dx 2
#define dy 2
//---------END-------//
int n,m;
char grid[22][22];
int mem[42][42][42][42];
int flag;
 
int get(int al,int ar,int bl,int br){
    if(bl>br||al>ar) return 0;
    if(mem[al][ar][bl][br]!=-1) return mem[al][ar][bl][br];
    set<int> sg;
    for(int i=0;i<n;i++){
        for(int j=((i%2)^flag);j<m;j+=2){
            int a=i+j,b=j-i+20;
            if(al<=a&&a<=ar&&b>=bl&&b<=br){
                int t;
                if(grid[i][j]=='R')
                    t=get(al,ar,b+2,br)^get(al,ar,bl,b-2);
                else if(grid[i][j]=='L')
                    t=get(al,a-2,bl,br)^get(a+2,ar,bl,br);
                else{
                    t=get(al,a-2,bl,b-2)^
                    get(al,a-2,b+2,br)^
                    get(a+2,ar,bl,b-2)^
                    get(a+2,ar,b+2,br);
                }
                sg.insert(t);
            }
        }
    }
    int r=0;
    while(sg.count(r)) r++;
    return mem[al][ar][bl][br]=r;
}
 
 
int main() {
    fio;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>grid[i];
    int a,b;
    memset(mem,-1,sizeof(mem));
    flag=1;
    a=get(0,40,0,40);
    memset(mem,-1,sizeof(mem));
    flag=0;
    b=get(0,40,0,40);
    cout<<(((a^b)==0)?"LOSE":"WIN")<<endl;
}