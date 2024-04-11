#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "equa.inp"
#define FILE_OUT "equa.out"
#define ofile                     \
    freopen(FILE_IN, "r", stdin); \
    freopen(FILE_OUT, "w", stdout)
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define nfio    \
    cin.tie(0); \
    cout.tie(0)
typedef long long int64;
typedef pair<int,int> ii;
typedef pair<int64,int> li;
 
int n,k,A[100005];
set<int> S;
map<int,int> M;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    for (int i=0;i<n;i++) cin>>A[i];
    for (int i=0;i<n;i++)
    {
        M[A[i]]++;
        if (M[A[i]]==1) S.insert(A[i]);
        else S.erase(A[i]);
        if (i>=k)
        {
            M[A[i-k]]--;
            if (M[A[i-k]]==1) S.insert(A[i-k]);
            else S.erase(A[i-k]);
        }
        if (i>=k-1)
        {
            if (S.empty()) cout<<"Nothing\n";
            else
            cout<<*(--S.end())<<"\n";
        }
    }
}