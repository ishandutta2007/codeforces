#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    string last = "";
    string iev;
    int sk = 0;
    for(int i = 0;i<n;i++){
        cin >> iev;
        if(iev != last){
            sk++;
        }
        last = iev;
    }
    cout << sk;
    return 0;
}