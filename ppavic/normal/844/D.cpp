#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 500;
const int FIR = 500;
const int MAXQ = 1950;

int bio[N];

struct node{
    int val,nxt,cur;
};

bool cmp(node A,node B){
    return A.val < B.val;
}

vector < node >  v;

int n,k,st,val,nx,t,ask,nxt;

int main(){
    srand(time(NULL));
    scanf("%d%d%d",&n,&st,&k);
    for(int i = 0;i<FIR;i++){
        int pit;
        if(i) pit = ((rand() * rand() % n) * rand()) % n + 1;
        else pit = st;
        if(bio[pit]){
            i--;
            continue;
        }
        bio[pit] = 1;
        printf("? %d\n",pit);
        fflush(stdout);
        scanf("%d %d",&val,&nxt);
        if(val == -1) return -1;
        node nw;nw.val = val;nw.nxt = nxt;nw.cur = pit;
        v.push_back(nw);
        ask++;
        if(ask == n) break;
    }
    sort(v.begin(),v.end(),cmp);
    node ans = v[v.size() - 1];

    if(v[0].val >= k){
        printf("! %d\n",v[0].val);
        fflush(stdout);
        return 0;
    }
    for(int i = 0;i<v.size() - 1;i++){
        if(v[i].val <= k && v[i+1].val > k){
            ans = v[i];break;
        }
    }
    int cur = ans.nxt,lst = ans.val;
    if(ans.val == k){
        printf("! %d\n",ans.val);
        fflush(stdout);
        return 0;
    }
    while(ask < MAXQ){
        if(cur == -1) break;
        printf("? %d\n",cur);
        fflush(stdout);
        scanf("%d %d",&val,&nxt);
        if(val == -1) return -1;
        if(val >= k){
            printf("! %d\n",val);
            fflush(stdout);
            return 0;
        }
        ask++;
        cur = nxt;
    }
    if(cur == -1 && val >= k){
        printf("! %d\n",val);
        fflush(stdout);
        return 0;
    }
    printf("! -1\n",val);
    fflush(stdout);
    return 0;
}