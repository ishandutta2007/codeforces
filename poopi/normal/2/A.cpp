                            /* in the name of Allah */
#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, sum[1010], p;
int fun[1010];
map <string, int> mp;
string name[1010];
int scr[1010];
int main(){
    cin >> n;
    string str;
    for(int i = 0; i < n; i++){
        cin >> str >> scr[i];
        name[i] = str;
        if(mp.find(str) == mp.end())
            mp[str] = p++;
        sum[mp[str]] += scr[i];
    }
    int mx = -1, idx = -1;
    for(int i = 0; i < p; i++)
        mx = max(mx, sum[i]);
    for(int i = 0; i < n; i++){
        int ref = mp[name[i]];
        fun[ref] += scr[i];
        if(sum[ref] == mx && fun[ref] >= mx){
            idx = i;
            break;
        }
    }
    cout << name[idx] << endl;
    return 0;
}