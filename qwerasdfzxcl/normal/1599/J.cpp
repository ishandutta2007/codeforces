#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, rn;
int arr[1002];
bool visited[1002];
int chk[30000002];

void solveIfEvenExist(){
    if(n<=2) return;
    bool evenExist = 0;
    for(int i=1; i<=n; i++) if(arr[i]%2==0) evenExist = 1;
    if(!evenExist) return;

    vector<int> even, odd;
    for(int i=1; i<=n; i++){
        if(arr[i]%2==0) even.push_back(arr[i]);
        else odd.push_back(arr[i]);
    }
    if((int)even.size() <= 2 && (int)odd.size() <= 1) return;

    int tmp;
    if((int)even.size() >= 3){
        puts("YES");
        for(int i=0; i<3; i++){
            printf("%d ", tmp = ((even[i] + even[(i+1)%3] - even[(i+2)%3]) / 2));
        }
        for(int i=3; i<(int)even.size(); i++) printf("%d ", even[i] - tmp);
        for(int i=0; i<(int)odd.size(); i++) printf("%d ", odd[i] - tmp);
    }
    else{
        puts("YES");
        vector<int> vec;
        vec.push_back(even[0]);
        for(auto x: odd) vec.push_back(x);
        for(int i=1; i<(int)even.size(); i++) vec.push_back(even[i]);

        for(int i=0; i<3; i++){
            printf("%d ", tmp = ((vec[i] + vec[(i+1)%3] - vec[(i+2)%3])) / 2);
        }
        for(int i=3; i<(int)vec.size(); i++) printf("%d ", vec[i] - tmp);
    }
    exit(0);
}

void solve(int A, int B){
    int C = A & B;
    A ^= C, B ^= C;
    assert(A && B);

    vector<int> vec1, vec2;
    for(int i=1; i<=n; i++){
        if((A>>i)&1){
            vec1.push_back(arr[i]);
            visited[i] = 1;
        }
    }

    for(int i=1; i<=n; i++){
        if((B>>i)&1){
            vec2.push_back(arr[i]);
            visited[i] = 1;
        }
    }

    int s = __builtin_popcount(A);
    puts("YES");

    int x = 0;
    for(int i=0; i<s; i++){
        printf("%d ", vec1[i] - x);
        x = vec1[i] - x;
        printf("%d ", vec2[i] - x);
        x = vec2[i] - x;
    }

    assert(x == 0);

    for(int i=1; i<=rn; i++){
        if(!visited[i]) printf("%d ", arr[i]);
    }
    exit(0);
}

int mask, sum, cnt, goal;

inline void dfs_small(int x){
    if(x==n+1) return;

    dfs_small(x+1);

    mask += 1<<x;
    sum += arr[x];
    cnt++;

    if(cnt == goal){
        if(chk[sum]){
            solve(chk[sum], mask);
            exit(0);
        }
        chk[sum] = mask;
    }
    else dfs_small(x+1);

    mask -= 1<<x;
    sum -= arr[x];
    cnt--;
}

inline void dfs_erase(int x){
    if(x==n+1) return;

    dfs_erase(x+1);

    mask += 1<<x;
    sum += arr[x];
    cnt++;

    if(cnt == goal){
        chk[sum] = 0;
    }
    else dfs_erase(x+1);

    mask -= 1<<x;
    sum -= arr[x];
    cnt--;
}

inline void dfs_big(int x){
    if(x==n+1) return;

    dfs_big(x+1);

    mask += (1<<x);
    sum += arr[x];
    cnt++;

    if(cnt == 13){
        if(chk[sum]){
            solve(mask, chk[sum]);
            exit(0);
        }
        chk[sum] = mask;
    }
    else dfs_big(x+1);

    mask -= (1<<x);
    sum -= arr[x];
    cnt--;
}

int main(){
    scanf("%d", &n);
    rn = n;
    for(int i=1; i<=n; i++) scanf("%d", &arr[i]);

    solveIfEvenExist();
    if(n>27) n = 27, dfs_big(1);
    else{
        for(goal = 1; goal*2 <= n; goal++) dfs_small(1), dfs_erase(1);
    }

    printf("NO");
}