//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=(1<<11)+10;
int p[N];
int dp[N][N];
int get(int i,int j){
    if (i>j) swap(i,j);
    if (dp[i][j]!=-1) return dp[i][j];
    cout<<"? "<<i<<" "<<j<<endl;
    cin>>dp[i][j];
    return dp[i][j];
}
int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    srand(time(NULL));
    int n;cin>>n;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    vector<int>r;
    for (int i=1;i<=n;i++) r.push_back(i);
    random_shuffle(r.begin(),r.end());
    reverse(r.begin(),r.end());
    r.push_back(0);
    reverse(r.begin(),r.end());
    int a=r[1];
    int b=r[2];
    int x=get(a,b);
    for (int it=3;it<=n;it++){
        int i=r[it];
//        cout<<"? "<<a<<" "<<i<<endl;
//        int y;cin>>y;
        int z=get(b,i);
        if (x==z) {
            b=i;
        }else if (z<x){
            a=i;
        }
        x=get(a,b);

    }
    vector<int>ans;
    int A=a;
    int B=b;
    for (int it=1;it<=n;it++){
        int i=r[it];
        if (i==A || i==B) continue;
        if (a!=-1 && b!=-1){
            int y=get(a,i);
            int z=get(b,i);
            p[i]=(min(y,z));
            if (y>z) a=-1;
            else if (y<z) b=-1;
        } else if (a!=-1){
            int y=get(a,i);
            p[i]=(y);
        } else if (b!=-1){
            int z=get(b,i);
            p[i]=(z);
        }
    }
    if (a==-1) p[A]=x;
    else p[B]=x;
    cout<<"! ";
    for (int i=1;i<=n;i++) cout<<p[i]<<" ";
    cout<<endl;
    return 0;
}
/*
4 6 3
1 2
2 3
3 4
4 1
1 3
2 4
*/