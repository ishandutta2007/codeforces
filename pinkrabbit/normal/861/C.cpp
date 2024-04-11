#include<cstdio>
char str[3002],lst1,lst2;
const bool c[26]={0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1};
int main(){
	scanf("%s",str); lst1=lst2=-1;
	for(int i=0;str[i]!='\0';++i){
//		printf("%d %d\n",lst1,lst2);
		str[i]-='a';
		if(!c[str[i]]) lst1=lst2=-1;
		else
			if(lst1!=-1&&lst2!=-1&&(!(lst1==lst2&&lst2==str[i]))) putchar(' '), lst1=lst2=-1;
		printf("%c",str[i]+'a');
		lst1=lst2; lst2=c[str[i]]?str[i]:-1;
	}
	return 0;
}