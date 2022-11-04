#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
#include<ctime>
#include<random>
using namespace std;
//const unsigned long long INF = 1e17;
const int INF = 2e7;
const int Y = 5000;
const long long m = 1000000007;
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
vector<int>Toans;
void Give9(int st) {
    Toans.push_back(st);
    Toans.push_back(st + 4);
    Toans.push_back(st + 8);
    Toans.push_back(st + 6);
    Toans.push_back(st + 2);
    Toans.push_back(st + 5);
    Toans.push_back(st + 1);
    Toans.push_back(st + 3);
    Toans.push_back(st + 7);
}
void solve(int st, int n) {
    if (n == 9) {
        Give9(st);
    }
    else {
        if (n == 8) {
            Toans.push_back(st);
            Toans.push_back(st + 3);
            Toans.push_back(st + 1);
            Toans.push_back(st + 4);
            Toans.push_back(st + 6);
            Toans.push_back(st + 2);
            Toans.push_back(st + 5);
            Toans.push_back(st + 7);
        }
        else {
            if (n == 7) {
                Toans.push_back(st);
                Toans.push_back(st + 3);
                Toans.push_back(st + 1);
                Toans.push_back(st + 4);
                Toans.push_back(st + 6);
                Toans.push_back(st + 2);
                Toans.push_back(st + 5);
            }
            else {
                if (n == 6) {
                    Toans.push_back(st);
                    Toans.push_back(st + 3);
                    Toans.push_back(st + 1);
                    Toans.push_back(st + 4);
                    Toans.push_back(st + 2);
                    Toans.push_back(st + 5);
                }
                else {
                    if (n == 5) {
                        Toans.push_back(st);
                        Toans.push_back(st + 3);
                        Toans.push_back(st + 1);
                        Toans.push_back(st + 4);
                        Toans.push_back(st + 2);
                    }
                    else {
                        if (n == 4) {
                            Toans.push_back(st + 1);
                            Toans.push_back(st + 3);
                            Toans.push_back(st);
                            Toans.push_back(st + 2);
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n <= 3) {
            cout << -1 << "\n";
            continue;
        }
        Toans.clear();
        int st = 1;
        while (n >= 18) {
            Give9(st);
            st += 9;
            n -= 9;
        }
        if (n < 9) {
            solve(1, n);
        }
        else {
            if (n == 9) {
                Give9(st);
            }
            else {
                if (n == 17) {
                    Give9(st);
                    st += 9;
                    Toans.push_back(st);
                    Toans.push_back(st + 3);
                    Toans.push_back(st + 1);
                    Toans.push_back(st + 4);
                    Toans.push_back(st + 6);
                    Toans.push_back(st + 2);
                    Toans.push_back(st + 5);
                    Toans.push_back(st + 7);
                }
                else {
                    if (n == 16) {
                        Give9(st);
                        st += 9;
                        Toans.push_back(st);
                        Toans.push_back(st + 3);
                        Toans.push_back(st + 1);
                        Toans.push_back(st + 4);
                        Toans.push_back(st + 6);
                        Toans.push_back(st + 2);
                        Toans.push_back(st + 5);
                    }
                    else {
                        if (n == 15) {
                            Give9(st);
                            st += 9;
                            Toans.push_back(st);
                            Toans.push_back(st + 3);
                            Toans.push_back(st + 1);
                            Toans.push_back(st + 4);
                            Toans.push_back(st + 2);
                            Toans.push_back(st + 5);
                        }
                        else {
                            if (n == 14) {
                                Give9(st);
                                st += 9;
                                Toans.push_back(st);
                                Toans.push_back(st + 3);
                                Toans.push_back(st + 1);
                                Toans.push_back(st + 4);
                                Toans.push_back(st + 2);
                            }
                            else {
                                if (n == 13) {
                                    Give9(st);
                                    st += 9;
                                    Toans.push_back(st + 1);
                                    Toans.push_back(st + 3);
                                    Toans.push_back(st);
                                    Toans.push_back(st + 2);
                                }
                                else {
                                    if (n == 12) {
                                        for (int i = 0; i <= 10; i += 2)Toans.push_back(st + i);
                                        Toans.push_back(st + 7);
                                        Toans.push_back(st + 11);
                                        Toans.push_back(st + 9);
                                        Toans.push_back(st + 5);
                                        Toans.push_back(st + 3);
                                        Toans.push_back(st + 1);
                                    }
                                    else {
                                        if (n == 11) {
                                            for (int i = 0; i <= 10; i += 2)Toans.push_back(st + i);
                                            Toans.push_back(st + 7);
                                            Toans.push_back(st + 9);
                                            Toans.push_back(st + 5);
                                            Toans.push_back(st + 3);
                                            Toans.push_back(st + 1);
                                        }
                                        else {
                                            if (n == 10) {
                                                Give9(st);
                                                Toans.push_back(st + 9);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (auto x : Toans)cout << x << " "; cout << endl;
    }
    return 0;
}