#include <bits/stdc++.h>
#define MAXN 100000

using namespace std;

string str;
bool viz[2][MAXN + 1];
int vf[3];

inline int check(bool t) {
    int sum = 0, i;
    for(i = 0; i < str.size(); i++)
       if(viz[t][i] == 0)
          sum += str[i] - '0';
    if(sum % 3 > 0)
       return MAXN + 1;
    i = 0;
    while(i < str.size() && (viz[t][i] == 1 || str[i] == '0')) {
        viz[t][i] = 1;
        i++;
    }
    int cnt = 0;
    for(i = 0; i < str.size(); i++)
        cnt += viz[t][i];
    return cnt;
}

int main() {
   // fstream cin("A.in");
   // ofstream cout("A.out");
    int i, cnt;
    ios::sync_with_stdio(false);
    cin >> str;
    int sum = 0;
    for(auto it : str) {
        sum += it - '0';
        vf[(it - '0') % 3]++;
    }
    if(sum % 3 == 1) {
        if(vf[1] == 0 && vf[2] < 2) {
            cout << -1;
            return 0;
        }
        else {
            i = str.size() - 1;
            while(i >= 0 && (str[i] - '0') % 3 != 1)
                i--;
            if(i >= 0)
                viz[0][i] = 1;
            i = str.size() - 1;
            cnt = 0;
            while(i >= 0 && cnt < 2) {
                if((str[i] - '0') % 3 == 2) {
                    cnt++;
                    viz[1][i] = 1;
                }
                i--;
            }
        }
    }
    else if(sum % 3 == 2){
        if(vf[2] == 0 && vf[1] < 2) {
            cout << -1;
            return 0;
        }
        else {
            i = str.size() - 1;
            while(i >= 0 && (str[i] - '0') % 3 != 2)
                i--;
            if(i >= 0)
                viz[0][i] = 1;
            i = str.size() - 1;
            cnt = 0;
            while(i >= 0 && cnt < 2) {
                if((str[i] - '0') % 3 == 1) {
                    cnt++;
                    viz[1][i] = 1;
                }
                i--;
            }
        }
    }
    int ans = min(check(0), check(1));
    if(ans == MAXN + 1)
        ans = -1;
    else if(ans == check(0)) {
        cnt = 0;
        for(i = 0; i < str.size(); i++)
            cnt += viz[0][i];
        if(cnt < str.size()) {
          for(i = 0; i < str.size(); i++)
            if(viz[0][i] == 0)
               cout << str[i];
        }
        else {
            if(vf[0] > 0)
               cout << 0;
            else
               cout << -1;
        }
    }
    else {
        cnt = 0;
        for(i = 0; i < str.size(); i++)
            cnt += viz[1][i];
        if(cnt < str.size()) {
          for(i = 0; i < str.size(); i++)
            if(viz[1][i] == 0)
               cout << str[i];
        }
        else {
            if(vf[0] > 0)
               cout << 0;
            else
               cout << -1;
        }
    }
   // cin.close();
   // cout.close();
    return 0;
}