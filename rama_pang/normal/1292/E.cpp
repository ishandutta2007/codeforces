/**
 * Strategy for using 5/4 + 1/((x-1)^2) + 1/(x^2) energy
 * Query for:
 * CC
 * CH
 * CO
 * OH
 * HH
 * 
 * We know for certain all C for index [1, n-1]
 * We know for certain all H for index [2, n]
 * 
 * For range [2, n-1], restore missing ones with O.
 * 
 * If the first element is still unknown, it might
 * be H or O.
 * 
 * If the last element is still unknown, it might
 * be C or O.
 * 
 * We can query once with length (n-1) for first
 * element, and [1, n] with length n for last element.
 * 
 * This is enough for n >= 5, however for n = 4 it
 * doesn't pass.
 * 
 * For n = 4
 * 
 * Ask
 * CH
 * CO
 * CC
 * 
 * Then split into cases. See code for details. (This is really painful)
 * 
 * If there is C, then minimum 2 slots will be filled:
 * For cases:
 * ??XX and XX??, we can use initial strategy
 * FOr case:
 * ?XX?, brute force with 9/16 energy to get answer
 * 
**/

#include <bits/stdc++.h>
using namespace std;
// #define STRESS
string ANSWER = "HHHH";

void solve() {
    int N;

    #ifdef STRESS
    N = ANSWER.size();
    #else
    cin >> N;
    #endif

    bool answered = false;
    string ans(N, '?');

    function<void(const string&)> Ask = [&](const string &s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') {
                cout << "! " << "H" << endl;
                int in;
                cin >> in;
                exit(0);
            }
        }
        deque<int> stressQuery;

        #ifdef STRESS
        for (int i = 0; i < N; i++) {
            if (string(begin(ANSWER) + i, begin(ANSWER) + i + s.size()) == s) {
                stressQuery.emplace_back(i + 1);
            }
        }
        #else
        cout << "? " << s << endl;
        #endif

        int k;
        
        #ifdef STRESS
        k = stressQuery.size();
        #else
        cin >> k;
        if (k == -1) {
            exit(0);
        }
        #endif
        
        while (k--) {
            int a;
            #ifdef STRESS
            a = stressQuery.front();
            stressQuery.pop_front();
            #else
            cin >> a;
            #endif
            a--;
            for (int i = 0; i < s.size(); i++) {
                if (ans[i + a] == '?') {
                    ans[i + a] = s[i];
                }
            }
        }
    };

    if (N == 4) {
        Ask("CH");
        Ask("CC");
        Ask("CO");
        if (ans == "????") {
            Ask("OH");
            if (ans == "????") {
                Ask("HHH");
                if (ans == "????") {
                    Ask("HOO");
                    if (ans == "HOO?") {
                        Ask("HOOO");
                        if (ans == "HOO?") {
                            ans = "HOOC";
                        }
                    } else if (ans == "?HOO") {
                        ans = "HHOO";
                    } else if (ans == "????") {
                        Ask("OOO");
                        if (ans == "OOO?") {
                            ans = "OOOC";
                        } else if (ans == "????") {
                            ans = "HHOC";
                        }
                    }
                    goto LAST_STRAT;
                } else {
                    if (ans == "HHHH") {
                        goto LAST_STRAT;
                    }
                    Ask("HHHC");
                    if (ans != "HHHC") {
                        ans = "HHHO";
                    }
                
                    goto LAST_STRAT;
                }
                goto LAST_STRAT;
            } else {
                bool found = true;
                for (int i = 0; i < 4; i++) {
                    if (ans[i] == '?') {
                        found = false;
                    }
                }
                if (found) {
                    goto LAST_STRAT;
                }
                string ask = ans;
                if (ans[0] == 'O' && ans[1] == 'H') {
                    ask[2] = 'O';
                    ask[3] = 'O';
                    Ask(ask);

                    ask[2] = 'O';
                    ask[3] = 'H';
                    Ask(ask);
                    
                    ask[2] = 'O';
                    ask[3] = 'C';
                    Ask(ask);
                    
                    ask[2] = 'H';
                    ask[3] = 'O';
                    Ask(ask);
                    
                    ask[2] = 'H';
                    ask[3] = 'H';
                    Ask(ask);
                    
                    ask[2] = 'H';
                    ask[3] = 'C';
                    Ask(ask);
                    
                } else if (ans[1] == 'O' && ans[2] == 'H') {
                    ask[0] = 'O';
                    ask[3] = 'O';
                    Ask(ask);

                    ask[0] = 'O';
                    ask[3] = 'H';
                    Ask(ask);
                    
                    ask[0] = 'O';
                    ask[3] = 'C';
                    Ask(ask);
                    
                    ask[0] = 'H';
                    ask[3] = 'O';
                    Ask(ask);
                    
                    ask[0] = 'H';
                    ask[3] = 'H';
                    Ask(ask);
                    
                    ask[0] = 'H';
                    ask[3] = 'C';
                    Ask(ask);
                    
                } else if (ans[2] == 'O' && ans[3] == 'H') {
                    ask[0] = 'O';
                    ask[1] = 'O';
                    Ask(ask);
                    
                    ask[0] = 'O';
                    ask[1] = 'H';
                    Ask(ask);

                    ask[0] = 'H';
                    ask[1] = 'O';
                    Ask(ask);

                    ask[0] = 'H';
                    ask[1] = 'H';
                    Ask(ask);
                }
                goto LAST_STRAT;
            }
        } else if (ans[0] == '?' && ans.back() == '?') {
            string ask = ans;
            ask[0] = 'C';
            ask.back() = 'C';
            Ask(ask);

            ask[0] = 'C';
            ask.back() = 'H';
            Ask(ask);

            ask[0] = 'C';
            ask.back() = 'O';
            Ask(ask);
            
            ask[0] = 'H';
            ask.back() = 'C';
            Ask(ask);
            
            ask[0] = 'H';
            ask.back() = 'H';
            Ask(ask);
            
            ask[0] = 'H';
            ask.back() = 'O';
            Ask(ask);
            
            ask[0] = 'O';
            ask.back() = 'C';
            Ask(ask);
            
            ask[0] = 'O';
            ask.back() = 'H';
            Ask(ask);
            
            ask[0] = 'O';
            ask.back() = 'O';
            Ask(ask);
            
            goto LAST_STRAT;
        } else {
            goto INITIAL_STRAT;
        }
    } else {
        Ask("CC");
        Ask("CH");
        Ask("CO");

        INITIAL_STRAT:

        Ask("OH");
        Ask("HH");
        for (int i = 1; i + 1 < N; i++) {
            if (ans[i] == '?') {
                ans[i] = 'O';
            }
        }

        LAST_STRAT:

        string ask = ans;
        if (ask[0] == '?' && ask.back() == '?') {
            ask[0] = 'H'; // H or O
            ask.back() = 'C'; // C or O
            Ask(ask);

            ask[0] = 'H'; // H or O
            ask.back() = 'O'; // C or O
            Ask(ask);
            
            ask[0] = 'O'; // H or O
            ask.back() = 'C'; // C or O
            Ask(ask);
            
            if (ans[0] == '?' && ans.back() == '?') {
                ans[0] = 'O';
                ans.back() = 'O';
            }       
        } else if (ask[0] == '?') {
            ask[0] = 'H';
            Ask(ask);
            ask[0] = 'C';
            Ask(ask);
            if (ans[0] == '?') {
                ans[0] = 'O';
            }
        } else if (ask.back() == '?') {
            ask.back() = 'H';
            Ask(ask);
            ask.back() = 'C';
            Ask(ask);
            if (ans.back() == '?') {
                ans.back() = 'O';
            }
        }

        #ifdef STRESS
        answered = true;
        if (ans != ANSWER) {
            cout << "WA: " << ANSWER << endl;
            exit(0);
        }
        #else
        answered = true;
        cout << "! " << ans << endl;
        #endif

    }

    if (!answered) {
        cout << "WA: " << ANSWER << endl;
        exit(0);
    }

}

int main() {
    int t;
    
    deque<string> ANSWERS;

    #ifdef STRESS
    #define REP(x) for (char x : {'H', 'C', 'O'})
        REP(a) REP(b) REP(c) REP(d) {
        string s;
        s.push_back(a);
        s.push_back(b);
        s.push_back(c);
        s.push_back(d);
        
        ANSWERS.emplace_back(s);
    }
    t = ANSWERS.size();
    #undef REP
    #else
    cin >> t;
    
    #endif
    clock_t z = clock();
    while (t--) {
        #ifdef STRESS
        ANSWER = ANSWERS.front();
        ANSWERS.pop_front();
        #endif

        solve();
        
        #ifndef STRESS
        int ac;
        cin >> ac;
        if (!ac) {
            break;
        }
        #endif
    }
    
    #ifdef STRESS
    cout << "AC" << endl;
    cout << 1000.00 * (clock() - z) / CLOCKS_PER_SEC << " ms\n";
    #endif

    return 0;
}