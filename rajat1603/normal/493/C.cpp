#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 5;
const int MAX = 2e9 + 9;

int n;
int a[N];
int m;
int b[N];
int ptr;
int ascore = 0;
int bscore = 0;
int curascore = 0;
int curbscore = 0;
int main(){
    cin >> n;

    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i];
    }

    cin >> m;

    for(int i = 1 ; i <= m ; ++i){
        cin >> b[i];
    }

    sort(a + 1 , a + 1 + n);
    sort(b + 1 , b + 1 + m);

    b[0] = INT_MIN;    
    ptr = m;
    curascore = n + n;
    curbscore = m + m;
    ascore = curascore;
    bscore = curbscore;

    for(int i = n ; i ; --i){
        ++curascore;
        while(b[ptr] >= a[i]){
            ++curbscore;
            --ptr;
        }
        if(curascore - curbscore >= ascore - bscore){
            ascore = curascore;
            bscore = curbscore;
        }
    }
    cout << ascore << ":" << bscore;
}