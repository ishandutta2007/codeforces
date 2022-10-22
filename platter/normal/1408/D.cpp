#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef pair<P,int> Pi;
P arr[2000];
P light[2000];
int val[2000];

int main(void) {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        scanf("%d %d",&arr[i].first,&arr[i].second);
    }
    for(int i=0;i<m;i++) {
        scanf("%d %d",&light[i].first,&light[i].second);
    }
    sort(light,light+m);
    vector<P> temp;
    temp.push_back(light[m-1]);
    int maxy=light[m-1].second;
    for(int i=m-2;i>=0;i--) {
        if (light[i].second>maxy) {
            temp.push_back(light[i]);
            maxy=light[i].second;
        }
    }
    reverse(temp.begin(),temp.end());
    m=temp.size();
    for(int i=0;i<m;i++) {
        light[i]=temp[i];
    }
    priority_queue<int> values;
    priority_queue<int> er;
    priority_queue<Pi,vector<Pi>,greater<Pi>> upd;
    for(int i=0;i<n;i++) {
        bool flag=false;
        for(int j=0;j<m;j++) {
            if (arr[i].first>light[j].first) {
                continue;
            }
            if (!flag) {
                val[i]=max(0,light[j].second+1-arr[i].second);
                flag=true;
            }
            int t;
            if (j==0) {
                t=0;
            }
            else {
                t=max(0,light[j-1].first+1-arr[i].first);
            }
            int ch=max(0,light[j].second+1-arr[i].second);
            upd.push(Pi(P(t,ch),i));
        }
        int t=max(0,light[m-1].first+1-arr[i].first);
        upd.push(Pi(P(t,0),i));
    }
    for(int i=0;i<n;i++) {
        values.push(val[i]);
    }
    int ret=1e9;
    for(int move=0;move<=1000005;move++) {
        while (!upd.empty()&&upd.top().first.first==move) {
            //printf("%d %d %d\n",upd.top().first.first,upd.top().first.second,upd.top().second);
            er.push(val[upd.top().second]);
            val[upd.top().second]=upd.top().first.second;
            values.push(val[upd.top().second]);
            upd.pop();
        }
        while (!er.empty()&&values.top()==er.top()) {
            er.pop();
            values.pop();
        }
        ret=min(ret,move+values.top());
    }
    printf("%d",ret);
}