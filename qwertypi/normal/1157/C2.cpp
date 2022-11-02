#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <deque>
#include <utility>
#include <numeric>
#include <map>
#include <math.h>
#define MAX 200002
#define inf (1 << 30)
#define se second
#define fi first
#define pb push_back
#define m1 998244353
#define epi 1e-12
#define NO "IMPOSSIBLE"
#define Ans(i, n) cout << "Case #" << i << ": " << n << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
using namespace std;

int A[MAX];

int L_count(int L, int R, int prev){
    int cnt = 0;
    while(R >= L){
        if(A[L] <= prev){
            break;
        }
        prev = A[L];
        L++;
        cnt++;
    }
    return cnt;
}

int R_count(int L, int R, int prev){
    int cnt = 0;
    while(R >= L){
        if(A[R] <= prev){
            break;
        }
        prev = A[R];
        R--;
        cnt++;
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    string ans;
    int L = 0;
    int R = n-1;
    int prev = -inf;
    while(R >= L){
        if(max(A[L], A[R]) <= prev){
            break;
        }
        if(A[L] > A[R]){
            if(A[R] > prev){
                ans.pb('R');
            }else{
                ans.pb('L');
            }
        }else if(A[L] < A[R]){
            if(A[L] > prev){
                ans.pb('L');
            }else{
                ans.pb('R');
            }
        }else{
            int cnt_L = L_count(L, R, prev);
            int cnt_R = R_count(L, R, prev);
            if(cnt_L >= cnt_R){
                for(int i=0;i<cnt_L;i++){
                    ans.pb('L');
                }
            }else{
                for(int i=0;i<cnt_R;i++){
                    ans.pb('R');
                }
            }
            break;
        }
        if(ans[(int)ans.size()-1] == 'R'){
            prev = A[R];
            R--;
        }else{
            prev = A[L];
            L++;
        }
    }
    int cnt = ans.size();
    cout << cnt << endl;
    cout << ans;
    return 0;
}