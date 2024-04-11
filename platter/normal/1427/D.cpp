#include<bits/stdc++.h>
using namespace std;

int arr[52];
int n;
vector<vector<int>> ret;

void rev(vector<int> v) {
    vector<vector<int>> temp;
    int sum=0;
    for(int i=0;i<v.size();i++) {
        vector<int> emp;
        for(int j=sum;j<sum+v[i];j++) {
            emp.push_back(arr[j]);
        }
        temp.push_back(emp);
        sum+=v[i];
    }
    reverse(temp.begin(),temp.end());
    int ind=0;
    for(int i=0;i<temp.size();i++) {
        for(int j=0;j<temp[i].size();j++) {
            arr[ind++]=temp[i][j];
        }
    }
}

int main(void) {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    for(int i=2;i<=n;i++) {
        int pos1=-1;
        for(int i=0;i<n;i++) {
            if (arr[i]==1) {
                pos1=i;
            }
        }
        vector<int> v;
        bool right=(pos1!=n-1);
        if (pos1!=n-1&&arr[pos1+1]==2) {
            right=true;
        }
        else if (pos1!=0&&arr[pos1-1]==2) {
            right=false;
        }
        for(int j=0;j<n;j++) {
            if (arr[j]==i) {
                if (j>pos1&&right) {
                    v.push_back(pos1);
                    for(int k=pos1;k<pos1+i-1;k++) {
                        v.push_back(1);
                    }
                    v.push_back(j-pos1-i+2);
                    v.push_back(n-j-1);
                }
                if (j>pos1&&!right) {
                    v.push_back(pos1-i+2);
                    v.push_back(i-1);
                    v.push_back(j-pos1);
                    v.push_back(n-j-1);
                }
                if (j<pos1&&right) {
                    v.push_back(j);
                    v.push_back(pos1-j);
                    v.push_back(i-1);
                    v.push_back(n-pos1-i+1);
                }
                if (j<pos1&&!right) {
                    v.push_back(j);
                    v.push_back(pos1-j-i+2);
                    for(int k=0;k<i-1;k++) {
                        v.push_back(1);
                    }
                    v.push_back(n-pos1-1);
                }
                break;
            }
        }
        rev(v);
        v.insert(v.begin(),(int)v.size());
        ret.push_back(v);
    }
    if (arr[0]!=1) {
        vector<int> v;
        v.push_back(n);
        for(int i=0;i<n;i++) {
            v.push_back(1);
        }
        rev(v);
        ret.push_back(v);
    }
    printf("%d\n",ret.size());
    for(int i=0;i<ret.size();i++) {
        int cnt=0;
        for(int j=1;j<ret[i].size();j++) {
            if (ret[i][j]!=0) {
                cnt++;
            }
        }
        printf("%d ",cnt);
        for(int j=1;j<ret[i].size();j++) {
            if (ret[i][j]!=0)
                printf("%d ",ret[i][j]);
        }
        printf("\n");
    }
}