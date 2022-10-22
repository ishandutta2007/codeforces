#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

int n, a, l[100005], r[100005], ans;
int l1[500005], r1[500005];
string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> s;
        for (int j=0; j<s.size(); j++){
            if (s[j] == ')'){
                if (l[i] > 0) l[i]--;
                else r[i]++;
            }
            else {
                l[i]++;
            }
        }
        if (l[i]==0 && r[i]==0){
            if (l1[0]){
                l1[0]--;
                ans++;
            }
            else l1[0]++;
        }
        else if (l[i] == 0){
            if (l1[r[i]]){
                l1[r[i]]--;
                ans++;
            }
            else {
                r1[r[i]]++;
            }
        }
        else if (r[i]==0) {
            if (r1[l[i]]){
                r1[l[i]]--;
                ans++;
            }
            else {
                l1[l[i]]++;
            }
        }
    }
    cout << ans;
}