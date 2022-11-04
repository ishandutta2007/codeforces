#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

string str;
pair <int, int> cnt[3];

inline int get1(char ch) {
    if(ch >= 'a' && ch <= 'z') {
        return 0;
    }
    if(ch >= 'A' && ch <= 'Z') {
        return 1;
    }
    return 2;
}

inline char get2(int x) {
    if(x == 0)
        return 'a';
    if(x == 1)
        return 'A';
    return '0';
}

int fr[3];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int t, i;
    ios::sync_with_stdio(false);
    cin >> t;
    while(t > 0) {
        t--;
        cin >> str;
        for(i = 0; i < 3; i++) {
            cnt[i].first = 0;
            cnt[i].second = i;
            fr[i] = 0;
        }
        for(auto it : str) {
            cnt[get1(it)].first++;
            fr[get1(it)]++;
        }
        sort(cnt, cnt + 3);
        if(cnt[1].first == 0) {
            for(i = 0; i + 1 < str.size(); i++) {
                //cerr << cnt[get1(str[i])].first << " " << cnt[get1(str[i + 1])].first - (get1(str[i]) == get1(str[i + 1])) << "\n";
                if(fr[get1(str[i])] > 1 && fr[get1(str[i + 1])] - (get1(str[i]) == get1(str[i + 1])) > 1) {
                    str[i] = get2(cnt[1].second);
                    str[i + 1] = get2(cnt[0].second);
                    break;
                }
            }
        }
        else if(cnt[0].first == 0) {
            for(i = 0; i < str.size(); i++) {
                if(fr[get1(str[i])] > 1) {
                    str[i] = get2(cnt[0].second);
                    break;
                }
            }
        }
        cout << str << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}