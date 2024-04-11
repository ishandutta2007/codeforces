#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 1e6 + 5;

char s[MAXN];
int n;
int classes[MAXN];
int bottom = 0, whereb = 0;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    gets(s);
    n = strlen(s);

    int bal = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++bal;
            classes[i] = 0;
        } else {
            classes[i] = 1;
            --bal;
        }
        if (bottom > bal) {
            bottom = bal;
        }
        if (bottom == bal) {
            whereb = i;
        }
    }

    for (int j = 1; j <= n * 2; j <<= 1) {
        vector <pair <pii, int> > tmpa;
        for (int i = 0; i < n; ++i) {
            //cout << classes[i] << " ";
            tmpa.puba(mapa(mapa(classes[i], classes[(i + j) % n]), i));
        }                             
        //cout << endl;
        sort(bend(tmpa));
        pii prev = tmpa[0].ff;
        int c = 0; 
        for (int i = 0; i < n; ++i) {
            if (prev != tmpa[i].ff) {
                ++c;
                prev = tmpa[i].ff;
            }
            classes[tmpa[i].ss] = c;
        }
    }

    /*
    for (int i = 0; i < n; ++i) {
        cout << classes[i] << " ";
    }
    cout << endl;
    */

    /*
    for (int i = 0; i < n; ++i) {
        suffarr[classes[i]] = i;
    }*/

    //cout << bottom << endl;

    if (bal <= 0) {
        int tmpbal = 0;
        pii best = mapa(1e9 + 9, -1);
        int nowmin = 0;
        for (int i = 0; i < n; ++i) {
            if (tmpbal == bottom || (nowmin >= tmpbal && tmpbal - bottom <= -bal)) {
                best = min(best, mapa(classes[i], i));
            }
            if (s[i] == '(') {
                ++tmpbal;
            } else {
                --tmpbal;
            }
            /*            
            if (tmpbal == bottom) {
                flag = true;
            }*/
            nowmin = min(nowmin, tmpbal);
        }

        for (int i = 0; i < -bal; ++i) {
            printf("(");
        }
        for (int i = 0; i < n; ++i) {
            printf("%c", s[(i + best.ss) % n]);
        }
        printf("\n");
        return 0;
    }

    bool can[MAXN];

    memset(can, 0, sizeof can);

    int nowbal = 0;
    int nowmin = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (nowbal <= nowmin) {
            can[i] = true;
        }
        if (s[i] == ')') {
            ++nowbal;
        } else {
            --nowbal;
        }
        nowmin = min(nowmin, nowbal);
    }

    int tmpbal = 0;
    //bool flag = false;
    pii best = mapa(1e9 + 9, -1);
    for (int i = 0; i < n; ++i) {
        if ((tmpbal - bottom <= bal && can[i]) || tmpbal == bottom) {
            best = min(best, mapa(classes[i], i));
        }
        if (s[i] == '(') {
            ++tmpbal;
        } else {
            --tmpbal;
        }        
    }    
    for (int i = 0; i < n; ++i) {
        printf("%c", s[(i + best.ss) % n]);
    }

    for (int i = 0; i < bal; ++i) {
        printf(")");
    }
    printf("\n");

    return 0;
}