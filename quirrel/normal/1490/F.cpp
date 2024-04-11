#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200009];
int s[200009];
main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a+1,a+n+1);
        int k = 1;
        vector<int> v;
        for(int i = 2; i <= n; i++){
            if(a[i] == a[i-1]) k++;
            else{
                v.push_back(k);
                k = 1;
            }
        }
        v.push_back(k);
        sort(v.begin(), v.end());
        int m = v.size();
        int ans = n - v[0] * m;
        for(int i = 0; i < v.size(); i++){
            ans = min(ans, n - v[i] * (m - i));
        }
        cout<<ans<<endl;
    }


}