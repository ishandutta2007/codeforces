#include<stdio.h>  
#include<string.h>  
int main()  
{  
    int i,sum;  
    char s1[30],s2[30];  
    scanf("%s%s",s1,s2);  
    sum=0;  
    for(i=0;i<strlen(s1);i+=2)  
    {  
        switch(s1[i])  
        {  
            case '8':  
            {  
                if(s2[i]=='[')sum++;  
                if(s2[i]=='(')sum--;  
                break;  
            }  
            case '[':  
            {  
                if(s2[i]=='8')sum--;  
                if(s2[i]=='(')sum++;  
                break;  
            }  
            case '(':  
            {  
                if(s2[i]=='8')sum++;  
                if(s2[i]=='[')sum--;  
            }  
        }  
    }  
    if(sum>0)printf("TEAM 1 WINS\n");  
    else if(sum<0)printf("TEAM 2 WINS\n");  
    else printf("TIE\n");  
    return 0;  
}