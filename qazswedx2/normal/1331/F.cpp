#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,fl=0;
char s[105];
char ta[1005]="HHeLiBeBCNOFNeNaMgAlSiPSClArKCaScTiVCrMnFeCoNiCuZnGaGeAsSeBrKrRbSrYZrNbMoTcRuRhPdAgCdInSnSbTeIXeCsBaLaCePrNdPmSmEuGdTbDyHoErTmYbLuHfTaWReOsIrPtAuHgTlPbBiPoAtRnFrRaAcThPaUNpPuAmCmBkCfEsFmMdNoLrRfDbSgBhHsMtDsRgCnNhFlMcLvTsOg";
void dfs(int dep)
{
	if(dep==n+1)
	{
		fl=1;
		return;
	}
	for(int i=0;ta[i];i++)
		if(ta[i+1]>='a'&&ta[i+1]<='z')
		{
			if(dep<n&&ta[i]==s[dep]&&ta[i+1]-'a'+'A'==s[dep+1])
				dfs(dep+2);
		}
		else
		{
			if(ta[i]==s[dep])
				dfs(dep+1);
		}
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	dfs(1);
	if(fl) printf("YES\n");
	else printf("NO\n");
	return 0;
}