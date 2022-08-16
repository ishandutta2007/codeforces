# include <cstdio>
# include <cstring>
# define CMAX 100001

int lcount[27],rcount[26];

int main()
{
    char l[CMAX],r[CMAX];
    scanf("%s%s",l,r);
    
    int ll=strlen(l),lr=strlen(r);
    int ret=0;
    if(lr>ll)goto bpp;
    for(int i=0;r[i];i++)
        rcount[r[i]-'a']++;
    for(int i=0;i<lr-1;i++)
        if(l[i]=='?')lcount[26]++;
        else lcount[l[i]-'a']++;
    for(int i=lr-1;i<ll;i++)
    {
        if(l[i]=='?')lcount[26]++;
        else lcount[l[i]-'a']++;
        bool flag=true;
        int subt=0;
        for(int j=0;j<26;j++)
        {
            if(lcount[j]<rcount[j])subt+=rcount[j]-lcount[j];
            if(subt>lcount[26]){flag=false;break;}
        }
        if(flag)ret++;
        if(l[i-lr+1]=='?')lcount[26]--;
        else lcount[l[i-lr+1]-'a']--;
    }
    bpp:
    printf("%d\n",ret);
}