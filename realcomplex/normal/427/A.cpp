#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

int main()
{
    int n;
    cin >> n;
    int sk;
    int of = 0;
    int unr = 0;
    for(int i = 0;i<n;i++){
        cin >> sk;
        if(sk > 0){
            of+=sk;
        }
        else{
            if(of == 0){
                unr++;
            }
            else{
                of--;
            }
        }
    }
    cout << unr;
    return 0;
}