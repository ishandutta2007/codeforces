#include <stdio.h>
#include <stdlib.h>

char str[100002];
long long numf[100002];
long long numb[100002];
long long mul[100002];
long long val[100002];


int main()
{
    scanf("%s", str);
    long long len=0;
    while (str[len]!=0) len += 1;
    mul[0]=1;
    for (long long i=1;i<100002;i++){
        mul[i]=mul[i-1]*10;
        mul[i]%=1000000007;
    }
    long long temp=str[0];
    numf[0]=temp-48;
    for (long long i=1;i<len;i++){
        numf[i] = (numf[i-1]*10);
        temp=str[i];
        numf[i] += temp-48;
        numf[i] %= 1000000007;
    }
    temp=str[len-1];
    numb[0]=temp-48;
    for (long long i=1;i<len;i++){
        numb[i] = numb[i-1];
        temp=str[len-1-i];
        numb[i] += (temp-48)*mul[i];
        numb[i] %= 1000000007;
    }
    val[0]=numf[0];
    for (long long i=1;i<len;i++){
        val[i]=val[i-1]+numf[i];
        val[i] %= 1000000007;
    }
    long long ans=0, temp1, temp2, temp3;
    ans += val[len-2];
    for (long long i=0;i<len-1;i++)
    {
        temp1=numb[i];
        temp1 *= (len-1-i);
        temp1 %= 1000000007;
        if (i<len-2){
            temp2=val[len-3-i];
            temp2 *= mul[i+1];
            temp2 %= 1000000007;
        }
        else temp2=0;
        temp3=(temp1+temp2)%1000000007;
        ans += temp3;
        ans %= 1000000007;
    }
    if (len==1) ans=0;
    printf("%lld", ans);
    return 0;
}