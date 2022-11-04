#include <bits/stdc++.h>
#define ll long long


using namespace std;

string good, str, a;

bool ok[26];


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, q;
    ios::sync_with_stdio(false);
    cin >> good;
    for(i = 0; i < good.size(); i++)
        ok[good[i] - 'a'] = 1;
    cin >> str;
    bool flag = 0;
    for(i = 0; i < str.size(); i++)
        if(str[i] == '*')
            flag = 1;
    cin >> q;
    while(q > 0) {
        q--;
        a.clear();
        cin >> a;
        if(flag == 0) {
            if(a.size() != str.size())
                cout << "NO";
            else {
                bool flag1 = 1;
                for(i = 0; i < a.size(); i++) {
                    if(str[i] == '?') {
                        if(ok[a[i] - 'a'] == 0)
                            flag1 = 0;
                    }
                    else if(a[i] != str[i])
                        flag1 = 0;
                }
                if(flag1 == 1)
                    cout << "YES";
                else
                    cout << "NO";
            }
        }
        else {
             if(a.size() < str.size() - 1)
                cout << "NO";
             else {
                 bool flag1 = 1;
                 int x = 0, p;
                 for(i = 0; i < str.size(); i++) {
                        if(str[i] == '?') {
                            if(ok[a[i - x] - 'a'] == 0)
                                flag1 = 0;
                        }
                        else if(str[i] == '*') {
                            x++;
                            p = i;
                        }
                        else if(a[i - x] != str[i])
                            flag1 = 0;
                  }
                  if(flag1 == 1 && str.size() - 1 == a.size())
                     cout << "YES";
                  else {
                     flag1 = 1;
                     for(i = 0; i < p; i++)
                        if(str[i] == '?') {
                            if(ok[a[i] - 'a'] == 0)
                                flag1 = 0;
                        }
                        else if(a[i] != str[i])
                            flag1 = 0;
                     int poz = a.size() - 1;
                     for(i = str.size() - 1; i > p; i--) {
                        if(str[i] == '?') {
                            if(ok[a[poz] - 'a'] == 0)
                                flag1 = 0;
                        }
                        else if(a[poz] != str[i])
                            flag1 = 0;
                        poz--;
                     }
                    if(flag1 == 0)
                        cout << "NO";
                    else {
                        for(i = p; i <= poz; i++)
                            if(ok[a[i] - 'a'] == 1)
                                  flag1 = 0;
                        if(flag1 == 0)
                            cout << "NO";
                        else
                            cout << "YES";
                    }
                  }
             }
        }
        cout << endl;
    }
    //cin.close();
    //cout.close();
    return 0;
}