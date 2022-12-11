#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second


int main()
{
    int n;
    cin >> n;
    vector<int>r;
    char s;
    for(int i = 0;i<n;i++){
        cin >> s;
        if(s == '2'){
            r.push_back(2);
        }
        else if(s == '3'){
            r.push_back(3);
        }
        else if(s == '4'){
            r.push_back(3);
            r.push_back(2);
            r.push_back(2);
        }
        else if(s == '5'){
            r.push_back(5);
        }
        else if(s == '6'){
            r.push_back(5);
            r.push_back(3);
        }
        else if(s == '7'){
            r.push_back(7);
        }
        else if(s == '8'){
            r.push_back(7);
            r.push_back(2);
            r.push_back(2);
            r.push_back(2);
        }
        else if(s == '9'){
            r.push_back(7);
            r.push_back(2);
            r.push_back(3);
            r.push_back(3);
        }
    }
    sort(r.begin(),r.end());
    reverse(r.begin(),r.end());
    for(int i = 0;i<r.size();i++){
        cout << r[i];
    }
    return 0;
}