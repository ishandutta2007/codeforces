#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef set < int > si;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const double EPS = 1e-9;
const double PI = 3.1415926535;

int ans1 = 0, ans2 = 0, bst = 0;


int main(){
    int n, m;scanf("%d%d", &n, &m);
    char s[n + 10][m + 10], ans[n + 10][m + 10];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            scanf(" %c", &s[i][j]);
        }
    }
    int sol = INF;
    ans1 = 0, ans2 = 0;
    for(int i = 0;i<n;i++){
        int s1[2], s2[2];
        s1[0] = 0;s1[1] = 0;
        s2[0] = 0;s2[1] = 0;
        for(int j = 0;j<m;j++){
            if(s[i][j] != 'A') s1[j % 2]++;
            if(s[i][j] != 'G') s1[1 - j % 2]++;
            if(s[i][j] != 'T') s2[j % 2]++;
            if(s[i][j] != 'C') s2[1 - j % 2]++;
        }
        if(i % 2 == 0){
            ans1 += min(s1[0], s1[1]);
            ans2 += min(s2[0], s2[1]);
        }
        else{
            ans2 += min(s1[0], s1[1]);
            ans1 += min(s2[0], s2[1]);
        }
    }
    if(ans1 <= sol){
        sol = ans1;
        bst = 0;
    }
    if(ans2 <= sol){
        sol = ans2;
        bst = 1;
    }
    ans1 = 0, ans2 = 0;
    for(int j = 0;j<m;j++){
        int s1[2], s2[2];
        s1[0] = 0;s1[1] = 0;
        s2[0] = 0;s2[1] = 0;
        for(int i = 0;i<n;i++){
            if(s[i][j] != 'A') s1[i % 2]++;
            if(s[i][j] != 'G') s1[1 - i % 2]++;
            if(s[i][j] != 'T') s2[i % 2]++;
            if(s[i][j] != 'C') s2[1 - i % 2]++;
        }
        if(j % 2 == 0){
            ans1 += min(s1[0], s1[1]);
            ans2 += min(s2[0], s2[1]);
        }
        else{
            ans2 += min(s1[0], s1[1]);
            ans1 += min(s2[0], s2[1]);
        }
    }
    if(ans1 <= sol){
        sol = ans1;
        bst = 2;
    }
    if(ans2 <= sol){
        sol = ans2;
        bst = 3;
    }
    ans1 = 0, ans2 = 0;
    for(int i = 0;i<n;i++){
        int s1[2], s2[2];
        s1[0] = 0;s1[1] = 0;
        s2[0] = 0;s2[1] = 0;
        for(int j = 0;j<m;j++){
            if(s[i][j] != 'A') s1[j % 2]++;
            if(s[i][j] != 'T') s1[1 - j % 2]++;
            if(s[i][j] != 'G') s2[j % 2]++;
            if(s[i][j] != 'C') s2[1 - j % 2]++;
        }
        if(i % 2 == 0){
            ans1 += min(s1[0], s1[1]);
            ans2 += min(s2[0], s2[1]);
        }
        else{
            ans2 += min(s1[0], s1[1]);
            ans1 += min(s2[0], s2[1]);
        }
    }
    if(ans1 <= sol){
        sol = ans1;
        bst = 4;
    }
    if(ans2 <= sol){
        sol = ans2;
        bst = 5;
    }
    ans1 = 0, ans2 = 0;
    for(int j = 0;j<m;j++){
        int s1[2], s2[2];
        s1[0] = 0;s1[1] = 0;
        s2[0] = 0;s2[1] = 0;
        for(int i = 0;i<n;i++){
            if(s[i][j] != 'A') s1[i % 2]++;
            if(s[i][j] != 'T') s1[1 - i % 2]++;
            if(s[i][j] != 'G') s2[i % 2]++;
            if(s[i][j] != 'C') s2[1 - i % 2]++;
        }
        if(j % 2 == 0){
            ans1 += min(s1[0], s1[1]);
            ans2 += min(s2[0], s2[1]);
        }
        else{
            ans2 += min(s1[0], s1[1]);
            ans1 += min(s2[0], s2[1]);
        }
    }
    if(ans1 <= sol){
        sol = ans1;
        bst = 6;
    }
    if(ans2 <= sol){
        sol = ans2;
        bst = 7;
    }
    ans1 = 0, ans2 = 0;
    for(int i = 0;i<n;i++){
        int s1[2], s2[2];
        s1[0] = 0;s1[1] = 0;
        s2[0] = 0;s2[1] = 0;
        for(int j = 0;j<m;j++){
            if(s[i][j] != 'A') s1[j % 2]++;
            if(s[i][j] != 'C') s1[1 - j % 2]++;
            if(s[i][j] != 'T') s2[j % 2]++;
            if(s[i][j] != 'G') s2[1 - j % 2]++;
        }
        if(i % 2 == 0){
            ans1 += min(s1[0], s1[1]);
            ans2 += min(s2[0], s2[1]);
        }
        else{
            ans2 += min(s1[0], s1[1]);
            ans1 += min(s2[0], s2[1]);
        }
    }
    if(ans1 <= sol){
        sol = ans1;
        bst = 8;
    }
    if(ans2 <= sol){
        sol = ans2;
        bst = 9;
    }
    ans1 = 0, ans2 = 0;
    for(int j = 0;j<m;j++){
        int s1[2], s2[2];
        s1[0] = 0;s1[1] = 0;
        s2[0] = 0;s2[1] = 0;
        for(int i = 0;i<n;i++){
            if(s[i][j] != 'A') s1[i % 2]++;
            if(s[i][j] != 'C') s1[1 - i % 2]++;
            if(s[i][j] != 'T') s2[i % 2]++;
            if(s[i][j] != 'G') s2[1 - i % 2]++;
        }
        if(j % 2 == 0){
            ans1 += min(s1[0], s1[1]);
            ans2 += min(s2[0], s2[1]);
        }
        else{
            ans2 += min(s1[0], s1[1]);
            ans1 += min(s2[0], s2[1]);
        }
    }
    if(ans1 <= sol){
        sol = ans1;
        bst = 10;
    }
    if(ans2 <= sol){
        sol = ans2;
        bst = 11;
    }
    if(bst % 4 < 2){
        char w1, w2, w3, w4;
        if(bst / 4 == 0) w1 = 'A', w2 = 'G', w3 = 'T', w4 =  'C';
        if(bst / 4 == 1) w1 = 'A', w2 = 'T', w3 = 'G', w4 =  'C';
        if(bst / 4 == 2) w1 = 'A', w2 = 'C', w3 = 'T', w4 =  'G';
        if(bst %2 == 1) swap(w1, w3), swap(w2, w4);

        for(int i = 0;i<n;i++){
            int s1 = 0, s2 = 0;
            for(int j = 0;j<m;j++){
                if(i % 2 == 0 && s[i][j] != w1) s1++;
                if(i % 2 == 0 && s[i][j] != w2) s2++;
                if(i % 2 == 1 && s[i][j] != w3) s1++;
                if(i % 2 == 1 && s[i][j] != w4) s2++;
                swap(w1, w2);swap(w3, w4);
            }
            if(m % 2 != 0) swap(w1, w2), swap(w3, w4);
            if(s1 > s2) swap(w1, w2), swap(w3, w4);
            for(int j = 0;j<m;j++){
                if(j % 2 == 0 && i % 2 == 0) ans[i][j] = w1;
                if(j % 2 == 1 && i % 2 == 0) ans[i][j] = w2;
                if(j % 2 == 0 && i % 2 == 1) ans[i][j] = w3;
                if(j % 2 == 1 && i % 2 == 1) ans[i][j] = w4;

            }
            if(s1 > s2) swap(w1, w2), swap(w3, w4);
        }
    }
    else{
        char w1, w2, w3, w4;
        if(bst / 4 == 0) w1 = 'A', w2 = 'G', w3 = 'T', w4 =  'C';
        if(bst / 4 == 1) w1 = 'A', w2 = 'T', w3 = 'G', w4 =  'C';
        if(bst / 4 == 2) w1 = 'A', w2 = 'C', w3 = 'T', w4 =  'G';
        if(bst %2 == 1) swap(w1, w3), swap(w2, w4);
        for(int j = 0;j<m;j++){
            int s1 = 0, s2 = 0;
            for(int i = 0;i<n;i++){
                if(j % 2 == 0 && s[i][j] != w1) s1++;
                if(j % 2 == 0 && s[i][j] != w2) s2++;
                if(j % 2 == 1 && s[i][j] != w3) s1++;
                if(j % 2 == 1 && s[i][j] != w4) s2++;
                swap(w1, w2);swap(w3, w4);
            }
            if(n % 2 != 0) swap(w1, w2), swap(w3, w4);
            if(s1 > s2) swap(w1, w2), swap(w3, w4);
            for(int i = 0;i<n;i++){
                if(i % 2 == 0 && j % 2 == 0) ans[i][j] = w1;
                if(i % 2 == 1 && j % 2 == 0) ans[i][j] = w2;
                if(i % 2 == 0 && j % 2 == 1) ans[i][j] = w3;
                if(i % 2 == 1 && j % 2 == 1) ans[i][j] = w4;

            }
            if(s1 > s2) swap(w1, w2), swap(w3, w4);
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}