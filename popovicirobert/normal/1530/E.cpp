#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define Test(x) cout << "Case #" << x << ": ";
 
using namespace std;







int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);


    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        string str;
        cin >> str;
        int n = (int)str.size();

        constexpr int SIGMA = 26;
        vector<int> freq(SIGMA);

        int cnt_ch = 0;
        for (auto itr : str) {
            freq[itr - 'a']++;
            if (freq[itr - 'a'] == 1) {
                cnt_ch++;
            }
        }

        int mn = n + 1;
        char ch;
        for (int i = 0; i < SIGMA; i++) {
            if (freq[i] > 0 && mn > freq[i]) {
                mn = freq[i];
                ch = i + 'a';
            }
        }

        if (mn == 1) { // 0
            string sol;
            sol += ch;
            freq[ch - 'a']--;
            for (int i = 0; i < SIGMA; i++) {
                while (freq[i]) {
                    freq[i]--;
                    sol += (i + 'a');
                }
            }
            cout << sol << "\n";
            continue;
        }

        if (mn == n) {
            cout << str << "\n";
            continue;
        }

        string sol;
        char ch_min, ch_first;
        for (int i = 0; i < SIGMA; i++) {
            if (freq[i]) {
                if (n - freq[i] + 2 >= freq[i]) {
                    ch_first = i + 'a';
                    break;
                }
            }
        }
        for (int i = 0; i < SIGMA; i++) {
            if (freq[i]) {
                ch_min = i + 'a';
                break;
            }
        }

        if (ch_first == ch_min) { // raspunsul e 1
            ch = ch_first;

            sol += ch;
            freq[ch - 'a']--;
            n--;
 
            while (n) {
                if (freq[ch - 'a']) {
                    freq[ch - 'a']--;
                    sol += ch;
                    n--;
                }
 
                for (int i = 0; i < SIGMA; i++) {
                    if (freq[i] && i + 'a' != ch) {
                        freq[i]--;
                        sol += (i + 'a');
                        n--;
                        break;
                    }
                }
            }
        } else { // 1
            ch = ch_min;

            char ch2, ch3;
            for (int i = 0; i < SIGMA; i++) {
                if (freq[i] && i + 'a' != ch) {
                    ch2 = i + 'a';
                    break;
                }
            }

            if (cnt_ch > 2) {
                for (int i = 0; i < SIGMA; i++) {
                    if (freq[i] && i + 'a' != ch && i + 'a' != ch2) {
                        ch3 = i + 'a';
                        break;
                    }
                }
     
                sol += ch;
                freq[ch - 'a']--;
                sol += ch2;
                freq[ch2 - 'a']--;
     
                while (freq[ch - 'a']) {
                    freq[ch - 'a']--;
                    sol += ch;
                }
                sol += ch3;
                freq[ch3 - 'a']--;
     
                for (int i = 0; i < SIGMA; i++) {
                    while (freq[i]--) {
                        sol += (i + 'a');
                    }
                }
            } else {
                sol += ch;
                freq[ch - 'a']--;

                while (freq[ch2 - 'a']) {
                    freq[ch2 - 'a']--;
                    sol += ch2;
                }
                while (freq[ch - 'a']) {
                    freq[ch - 'a']--;
                    sol += ch;
                }
            }
        }

        cout << sol << "\n";
    }
    

    return 0;
}