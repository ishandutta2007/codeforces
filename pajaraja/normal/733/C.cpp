#include <iostream>
#include <stdio.h>
int a[507],b[507],br[507];
int main(int argc, char** argv) 
{
	int n,k;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	scanf("%d",&k);
	for(int i=0;i<k;i++) scanf("%d",&b[i]);
	int p=0,sj=0,sum=0;
	br[0]=-1;
	for(int i=0;i<n;i++)
	{
		if(sum==0) sj=a[i];
		sum+=a[i];
		if(a[i]!=sj) sj=-1;
		if(sum==b[p])
		{
			p++;
			br[p]=i;
			sum=0;
			if((sj!=-1&&(i-br[p-1]!=1))||p==k+1)
			{
				printf("NO"); 
			    return 0;
			}
		}
		if(sum>b[p]) 
		{
		    printf("NO"); 
			return 0;
		}
	}
	if(p!=k||sum!=0) 
	{
	    printf("NO"); 
		return 0;
	}
	printf("YES\n");
	for(int i=0;i<k;i++)
	{
		int max=0,ind,w;
		for(int j=br[i]+1;j<=br[i+1];j++) max=max>a[j]?max:a[j];
		if(max!=a[br[i]+1]) for(int j=br[i]+1;j<=br[i+1];j++) 
		{
			if(a[j]==max) 
		    {
			    ind=j;
		        break;
		    }
	    }
		else
		{
		    for(int j=br[i]+1;j<=br[i+1];j++) if(max!=a[j]) 
		    {
			    ind=j-1;
			    break;
		    }
		}
		w=max;
		while(br[i+1]-br[i]>1)
		{
			if(w>a[ind+1]&&ind!=br[i+1])
			{
				printf("%d R\n",ind+1);
				w+=a[ind+1];
				a[ind]+=a[ind+1];
				for(int j=ind+1;j<n-1;j++) a[j]=a[j+1];
				n--;
				for(int j=i+1;j<=k;j++) br[j]--;
			}
			if(ind!=0) 
			{
			if(w>a[ind-1]&&ind-1!=br[i])
			{
				printf("%d L\n",ind+1);
				w+=a[ind-1];
				a[ind]+=a[ind-1];
				for(int j=ind;j<n-1;j++) a[j]=a[j+1];
				n--;
				for(int j=i+1;j<=k;j++) br[j]--;
				ind--;
			}
		    }
		} 
	}
	return 0;
}