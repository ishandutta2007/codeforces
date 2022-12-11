#include <bits/stdc++.h>

using namespace std;

vector<int>divisor(int sk){
    vector<int>re;
    for(int i = 1;i<=sqrt(sk);i++){
        if(sk%i==0){
            re.push_back(i);
            re.push_back(sk/i);
        }
    }
    return re;
}
int main()
{
    int a,b;
    cin >> a >> b;
    int t = __gcd(a,b);
    vector<int>to = divisor(t);
    sort(to.begin(),to.end());
    int n;
    cin >> n;
    int s,f;
    int sk,en,mi;
    int ans;
    for(int i = 0;i<n;i++){
        cin >> s >> f;
        sk = -1;
        en = to.size();
        ans = upper_bound(to.begin(),to.end(),f) - to.begin();
        ans--;
        if(ans == -1 || to[ans] < s){
            cout << -1 << "\n";
        }
        else{
            cout << to[ans] << "\n";
        }
    }
    return 0;
}