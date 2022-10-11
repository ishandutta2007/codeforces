// Not my code
// https://codeforces.com/contest/1271/submission/66981122


/******************************************************************************
 
                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.
 
*******************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
 
bool notsame(char* c, int len)
{
    bool a = false;
    for(int i=0;i<len-1;++i)
    {
        if(c[i]!=c[i+1]) a= true;
    }
    
    return a;
}
 
bool notpresent(int* nums, int ele, int idx)
{
    bool a= true;
    for(int i=0;i<idx;i++)
    {
        if(nums[i]==ele) a=false;
    }
    return a;
}
 
int main()
{
    int len;
    scanf("%d",&len);
    char* c= (char* ) malloc(sizeof(char)*(len + 1));
    int * nums= (int*) malloc(sizeof(int)*3*len);
    int k=0;
    scanf("%s",c);
    int nob=0;
    int now=0;
    for(int i=0;i<len;i++)
    {
        if(c[i]=='B') nob++;
        if(c[i]=='W') now++;
    }
    int num=0;
    if(now%2==1&&nob%2==1) {printf("-1"); return 0;
    }
    else{
        
        for(int i=0;i<len-2;i++)
        {
         if(c[i]!=c[i+1]){
             if(c[i+1]=='B') c[i+1]='W'; else c[i+1]='B';
             if(c[i+2]=='B') c[i+2]='W'; else c[i+2]='B';
            num++;
             nums[k++]= i+1;
         }
        }
        for(int i=0;i<len-1;i++)
        {
            if(!notsame(c, len)){ break;}
            if(c[i]==c[i+1]){
                num++;
            if(c[i]=='B'){ c[i]='W';c[i+1]='W';}
            else if(c[i]=='W') { c[i]='B'; c[i+1]= 'B';}
             nums[k++]= i;
        }
        }
    
    printf("%d\n",num);
    for(int i=0;i<k;i++)
    printf("%d ",nums[i]+1);
    return 0;
 
}
}