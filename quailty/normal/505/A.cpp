#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<char>t;
void copy(int n,char s[])
{
    for(int k=0;k<n;k++){
        t.push_back(s[k]);
    }
}
bool judge()
{
    int i,len=t.size();
    for(i=0;i<len;i++){
        if(t[i]!=t[len-1-i])break;
    }
    if(i==len)return 1;
    else return 0;
}
int main()
{
    char s[15];
    bool flag=0;
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i<=n;i++){
        if(flag)break;
        for(int j=0;j<26;j++){
            t.clear();
            copy(n,s);
            vector<char>::iterator itr=t.begin();
            t.insert(itr+i,'a'+j);
            if(judge()){
                flag=1;
                break;
            }
        }
    }
    if(flag){
        for(int i=0;i<n+1;i++)
            printf("%c",t[i]);
        printf("\n");
    }
    else printf("NA\n");
    return 0;
}