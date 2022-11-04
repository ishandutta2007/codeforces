#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while (t--){
        int a, b, c;
        cin >> a >> b >> c;
        int dif = max(a, b) - min(a, b);
        int ans1 = c + dif, ans2 = c - dif, maxx = dif * 2;
        if(c>maxx){
            cout<<"-1\n";
            continue;
        }
        if (a >= 1 && a <= maxx && b >= 1 && b <= maxx && ans1 >= 1 && ans1 <= maxx)
            cout << ans1;
        else if (a >= 1 && a <= maxx && b >= 1 && b <= maxx && ans2 >= 1 && ans2 <= maxx)
            cout << ans2;
        else
            cout << -1;
        cout << endl;
    }
    return 0;
}