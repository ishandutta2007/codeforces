#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
double a[200001];
int ans[200001];
int f(int x){
    x++;
    while (x%10==0) x/=10;
    return x;
}
int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    int n;cin>>n;
    set<int>st;
    while (st.find(n)==st.end()){
        st.insert(n);
        n=f(n);
    }
    cout<<st.size();
    return 0;
}