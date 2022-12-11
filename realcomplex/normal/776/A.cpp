#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define f first
#define s second
#define t abs


int main(){

    string a,b;
    cin >> a >> b;
    int n;
    cin >> n;
    string f,s;
    cout << a << " " << b << "\n";
    for(int i = 0;i<n;i++){
        cin >> f >> s;
        if(f == a){
            a = s;
        }
        else if(f == b){
            b = s;
        }
        cout << a << " " << b << "\n";
    }
    return 0;
}