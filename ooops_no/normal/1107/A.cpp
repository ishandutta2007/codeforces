/*
_NUUUUUUU_
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>

using namespace std;
typedef long long ll;

const ll INF = (ll) 1e18;

int main() {
	ll n;
	cin >> n;
	for (int i=0; i<n; i++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s.length()>2){
            cout << "YES" << endl;
            cout << 2 << endl;
            cout << s[0] << " " << s.substr(1, n-1) << endl;
        }
        else{
            if ((ll)s[1] > (ll)s[0]){
                cout << "YES" << endl;
                cout << 2 << endl;
                cout << s[0] << " " << s.substr(1, n-1) << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
	}
}