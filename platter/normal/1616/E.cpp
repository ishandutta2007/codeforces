#include <bits/stdc++.h>
using namespace std;

char s[100001];
char t[100001];
const int sz=131072;
typedef pair<int,char> P;

struct Seg {
    int seg[sz*2];
    int sum(int l,int r,int node=1,int nodel=0,int noder=sz-1) {
        if (l>r) {
            return 0;
        }
        if (r<nodel||l>noder) {
            return 0;
        }
        if (l<=nodel&&noder<=r) {
            return seg[node];
        }
        int mid=(nodel+noder)/2;
        return sum(l,r,node*2,nodel,mid)+sum(l,r,node*2+1,mid+1,noder);
    }
    void update(int i,int val) {
        i+=sz;
        seg[i]=val;
        while (i>1) {
            i/=2;
            seg[i]=seg[i*2]+seg[i*2+1];
        }
    }
};

int main() {
    int tc;
    scanf("%d",&tc);
    Seg seg;
    for(int te=0;te<tc;te++) {
        int n;
        scanf("%d\n",&n);
        scanf("%s%s",s,t);
        queue<int> v[26];
        for(int i=0;i<n;i++) {
            v[s[i]-'a'].push(i);
            seg.update(i,1);
        }
        long long ret=1e12;
        long long val=0;
        priority_queue<P,vector<P>,greater<P>> pq;
        priority_queue<P,vector<P>,greater<P>> er;
        for(int i=0;i<n;i++) {
            pq.push(P(i,s[i]));
        }
        for(int i=0;i<n;i++) {
            //printf("%d %d\n",i,val);
            char now;
            while (!er.empty()&&pq.top()==er.top()) {
                pq.pop();
                er.pop();
            }
            now=pq.top().second;
            if (now<t[i]) {
                ret=min(ret,val);
                break;
            }
            if (now>=t[i]) {
                int pos=-1;
                int mn=1e6;
                for(int j=0;j<t[i]-'a';j++) {
                    if (!v[j].empty()&&v[j].front()<mn) {
                        pos=j;
                        mn=v[j].front();
                    }
                }
                if (pos!=-1) {
                    ret=min(ret,val+seg.sum(0,mn-1));
                }
                if (v[t[i]-'a'].empty()) {
                    break;
                }
                val+=seg.sum(0,v[t[i]-'a'].front()-1);
                seg.update(v[t[i]-'a'].front(),0);
                er.push(P(v[t[i]-'a'].front(),t[i]));
                v[t[i]-'a'].pop();
            }
        }
        printf("%lld\n",ret>=100000000000LL?-1:ret);
    }
    return 0;
}