#include <bits/stdc++.h>
using namespace std;
void read(int& x){ scanf("%d",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }

unordered_set<string> s;

int a, b, c;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    for(;n--;){
        string tmp;
        cin >> tmp;
        s.insert(tmp);
        ++a;
    }
    for(;m--;){
        string tmp;
        cin >> tmp;
        if(s.find(tmp) == s.end()){
            ++c;
        } else {
            --a;
            ++b;
        }
    }
    if(a > c){
        cout << "YES" << endl;
    } else if(a < c){
        cout << "NO" << endl;
    } else {
        b %= 2;
        if(b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}