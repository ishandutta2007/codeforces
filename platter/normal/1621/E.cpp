#include <bits/stdc++.h>
using namespace std;

long long arr[100000];
typedef pair<long long,long long> P;
typedef pair<P,int> Pi;
Pi brr[100000];
vector<int> v[100000];

bool comp(Pi a,Pi b) {
    return a.first.first*b.first.second<b.first.first*a.first.second;
}

int p[200000];

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n,m;
        scanf("%d %d",&n,&m);
        vector<int> v0; //    
        vector<int> v1; //  
        vector<int> v2; //    
        for(int i=0;i<m;i++) {
            v[i].clear();
            brr[i].first.first=0;
        }
        for(int i=0;i<n;i++) {
            scanf("%lld",&arr[i]);
        }
        sort(arr,arr+n);
        reverse(arr,arr+n);
        reverse(arr,arr+m);
        for(int i=0;i<m;i++) {
            int sz;
            scanf("%d",&sz);
            brr[i].first.second=sz;
            brr[i].second=i;
            for(int j=0;j<sz;j++) {
                int x;
                scanf("%d",&x);
                v[i].push_back(x);
                brr[i].first.first+=x;
            }
        }
        sort(brr,brr+m,comp);
        for(int i=0;i<m;i++) {
            p[brr[i].second]=i;
        }
        for(int i=0;i<m;i++) {
            if (i==m-1) {
                v0.push_back(i);
            }
            else if (brr[i].first.first>arr[i+1]*brr[i].first.second) {
                v0.push_back(i);
            }
            if (brr[i].first.first>arr[i]*brr[i].first.second) {
                v1.push_back(i);
            }
            if (i==0) {
                v2.push_back(i);
            }
            else if (brr[i].first.first>arr[i-1]*brr[i].first.second) {
                v2.push_back(i);
            }
        }
        v0.push_back(m+5);
        v1.push_back(m+5);
        v2.push_back(m+5);
        for(int i=0;i<m;i++) {
            for(int j=0;j<v[i].size();j++) {
                P now=brr[p[i]].first;
                now.first-=v[i][j];
                now.second--;
                int lo=-1; //now>=brr[lo]
                int hi=m; //now<brr[hi]
                while (lo+1<hi) {
                    int mid=(lo+hi)/2;
                    if (now.first*brr[mid].first.second>=brr[mid].first.first*now.second) {
                        lo=mid;
                    }
                    else {
                        hi=mid;
                    }
                }
                //printf("%d ",lo);
                //printf("%d %d ",now.first,now.second);
                bool flag=true;
                if (lo<p[i]-1) {
                    if (*lower_bound(v0.begin(),v0.end(),lo+1)<=p[i]-1) {
                        flag=false;
                    }
                    if (*lower_bound(v1.begin(),v1.end(),0)<=lo) {
                        flag=false;
                    }
                    if (*lower_bound(v1.begin(),v1.end(),p[i]+1)<m) {
                        flag=false;
                    }
                    if (now.first>arr[lo+1]*now.second) {
                        flag=false;
                    }
                }
                else if (lo>p[i]) {
                    if (*lower_bound(v2.begin(),v2.end(),p[i]+1)<=lo) {
                        flag=false;
                    }
                    if (*lower_bound(v1.begin(),v1.end(),0)<p[i]) {
                        flag=false;
                    }
                    if (*lower_bound(v1.begin(),v1.end(),lo+1)<m) {
                        flag=false;
                    }
                    if (now.first>arr[lo]*now.second) {
                        flag=false;
                    }
                }
                else {
                    if (*lower_bound(v1.begin(),v1.end(),0)<p[i]) {
                        flag=false;
                    }
                    if ((*lower_bound(v1.begin(),v1.end(),p[i]+1))<m) {
                        flag=false;
                    }
                    if (now.first>arr[p[i]]*now.second) {
                        flag=false;
                    }
                }
                printf("%d",flag);
            }
        }
        printf("\n");
    }
    return 0;
}