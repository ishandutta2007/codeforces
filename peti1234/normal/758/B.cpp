#include <bits/stdc++.h>

using namespace std;
string p;
int o, e, k, h;
int main()
{
    cin >> p;
    for (int i=0; i<p.size(); i+=4) {
        if (p[i]=='!') {
            o++;
        }
        else {
            if (o<100) {
                if (p[i]=='R') {
                    o+=400;
                }
                if (p[i]=='B') {
                    o+=300;
                }
                if (p[i]=='Y') {
                    o+=200;
                }
                if (p[i]=='G') {
                    o+=100;
                }
            }
        }
    }
    for (int i=1; i<p.size(); i+=4) {
        if (p[i]=='!') {
            e++;
        }
        else {
            if (e<100) {
                if (p[i]=='R') {
                    e+=400;
                }
                if (p[i]=='B') {
                    e+=300;
                }
                if (p[i]=='Y') {
                    e+=200;
                }
                if (p[i]=='G') {
                    e+=100;
                }
            }
        }
    }
    for (int i=2; i<p.size(); i+=4) {
        if (p[i]=='!') {
            k++;
        }
        else {
            if (k<100) {
                if (p[i]=='R') {
                    k+=400;
                }
                if (p[i]=='B') {
                    k+=300;
                }
                if (p[i]=='Y') {
                    k+=200;
                }
                if (p[i]=='G') {
                    k+=100;
                }
            }
        }
    }
    for (int i=3; i<p.size(); i+=4) {
        if (p[i]=='!') {
            h++;
        }
        else {
            if (h<100) {
                if (p[i]=='R') {
                    h+=400;
                }
                if (p[i]=='B') {
                    h+=300;
                }
                if (p[i]=='Y') {
                    h+=200;
                }
                if (p[i]=='G') {
                    h+=100;
                }
            }
        }
    }
    if (o>=400) {
        cout << o-400 << " ";
    }
    if (e>=400) {
        cout << e-400 << " ";
    }
    if (k>=400) {
        cout << k-400 << " ";
    }
    if (h>=400) {
        cout << h-400 << " ";
    }
    if (o>=300 && o<400) {
        cout << o-300 << " ";
    }
    if (e>=300 && e<400) {
        cout << e-300 << " ";
    }
    if (k>=300 && k<400) {
        cout << k-300 << " ";
    }
    if (h>=300 && h<400) {
        cout << h-300 << " ";
    }
    if (o>=200 && o<300) {
        cout << o-200 << " ";
    }
    if (e>=200 && e<300) {
        cout << e-200 << " ";
    }
    if (k>=200 && k<300) {
        cout << k-200 << " ";
    }
    if (h>=200 && h<300) {
        cout << h-200 << " ";
    }
    if (o<200) {
        cout << o-100 << " ";
    }
    if (e<200) {
        cout << e-100 << " ";
    }
    if (k<200) {
        cout << k-100 << " ";
    }
    if (h<200) {
        cout << h-100 << " ";
    }
    return 0;
}