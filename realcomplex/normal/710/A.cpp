#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

int l[10][10];

int main(){

    char a,b;
    cin >> a >> b;
    for(int i = 0;i<10;i++){
        for(int x = 0;x<10;x++){
            if(i == 0|| x == 0 || i == 9|| x == 9){
                l[i][x] = 0;
            }
            else{
                l[i][x] = 1;
            }
        }
    }
    int fp,sp;
    fp = b-48;
    sp = a-96;
    l[fp][sp] = 1;
    cout << (l[fp][sp+1]) + (l[fp][sp-1]) + (l[fp+1][sp]) + (l[fp-1][sp]) + (l[fp-1][sp-1]) + (l[fp+1][sp+1]) + (l[fp-1][sp+1]) + (l[fp+1][sp-1]);
    return 0;
}