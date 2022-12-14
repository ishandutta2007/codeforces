#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;

int N,D,F;
int carry[100010],f[100010],d[100010];
int anscnt = 0, ansfuel = 0;

vector <int> v;

void func1(void){ // only carry = 0 moves
    int i;
    
    v.clear();
    REP(i,N) if(carry[i] == 0 && d[i] >= D) v.push_back(f[i]);
    sort(v.begin(),v.end());
    
    int sum = 0;
    REP(i,v.size()){
        sum += v[i];
        if(sum > F) break;
        if(i+1 > anscnt || (i+1 == anscnt && sum < ansfuel)){
            anscnt = i + 1;
            ansfuel = sum;
        }
    }
}

vector <int> a,b;

void func2(void){ // carry > 0 moves
    int i,j;
    
    bool found = false;
    REP(i,N) if(carry[i] > 0 && f[i] <= F && d[i] >= D) found = true;
    if(!found) return;
    
    int C = 0;
    REP(i,N){
        C += carry[i];
        C = min(C, N);
    }
    
    REP(i,N) if(d[i] >= D) if(carry[i] > 0) a.push_back(f[i]); else b.push_back(f[i]);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    // choose at least one from a
    int sum = a[0];
    i = 1; j = 0;
    
    while(1){
        int cnt = min(i+j+C, N);
        if(cnt > anscnt || (cnt == anscnt && sum < ansfuel)){
            anscnt = cnt;
            ansfuel = sum;
        }
        
        if(i == a.size() && j == b.size()) break;
        if(i < a.size() && (j == b.size() || a[i] < b[j])){
            sum += a[i];
            i++;
        } else {
            sum += b[j];
            j++;
        }
        
        if(sum > F) break;
    }
}

int main(void){
    int i;
    
    cin >> N >> D >> F;
    REP(i,N) scanf("%d%d%d", &carry[i], &f[i], &d[i]);
    
    func1(); func2();
    
    cout << anscnt << ' ' << ansfuel << endl;
    
    return 0;
}