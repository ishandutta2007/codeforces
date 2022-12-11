#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second

int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    cin >> n >> m;
    int l[n];
    for(int i = 0;i<n;i++){
        cin >> l[i];
    }
    sort(l,l+n);
    int sum = 0;
    for(int i = 0;i<n;i++){
        if(l[i] < 0 && m>0){
            sum += abs(l[i]);
            m--;
        }
    }
    cout << sum;
    return 0;
}