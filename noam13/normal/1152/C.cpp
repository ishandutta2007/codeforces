#include<bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);i++)
#define chkmin(a,b) a=min((a),(b))
#define chkmax(a,b) a=max(a,b)
using namespace std;
const int INF=4*1e18;

int gcd(int a, int b) {
   if (b == 0) return a;
   if (b>a) swap(a,b);
   return gcd(b, a % b);
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}

int32_t main(){
    int a,b,d;cin>>a>>b;
    if (b<a) swap(a,b);
    d=b-a;
    int val,k,g;
    ii bk=mp(lcm(a,b),0);
    for(int i=1;i*i<=d;i++){
        k=(i-a%i)%i;
        val=lcm(a+k,b+k);
        chkmin(bk,mp(val,k));
        g=d/i;
        k=(g-(a%g))%g;
        val=lcm(a+k,b+k);
        chkmin(bk,mp(val,k));
    }
    cout<<bk.y<<endl;
    return 0;
}