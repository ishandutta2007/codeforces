#include <bits/stdc++.h>


using namespace std;

string str;
long long n;

bool x;

inline int get_lvl(long long nod) {
    int lvl = 0;
    for(long long i = 1; i <= n; i *= 2) {
        if((nod - i) % (2 * i) == 0) {
           x = ((nod - i) / (2 * i)) % 2;
           return lvl;
        }
        lvl++;
    }
}

int main() {
   // fstream cin("A.in");
   // ofstream cout("A.out");
    int q;
    ios::sync_with_stdio(false);
    cin >> n >> q;
    long long p2 = 1;
    int cnt = 0;
    while(p2 < n) {
        p2 *= 2;
        cnt++;
    }
    if(cnt > 0)
        cnt--;
    //printf("%d\n" ,cnt);
    while(q > 0) {
        q--;
        str.clear();
        long long nod;
        cin >> nod;
        cin >> str;
        for(auto it : str) {
            int lvl = get_lvl(nod);
            if(it == 'L' && lvl > 0)
                nod -= (1LL << (lvl - 1));
            if(it == 'R' && lvl > 0)
                nod += (1LL << (lvl - 1));
            if(it == 'U' && lvl != cnt) {
                if(x == 0)
                    nod += (1LL << lvl);
                else
                    nod -= (1LL << lvl);
            }
        }
        cout << nod << endl;
    }
  //  cin.close();
  //  cout.close();
    return 0;
}