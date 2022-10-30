program storm;
const pro:array[1..184] of longint = (2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269
                                      ,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,
                                      587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,
                                      911,919,929,937,941,947,953,967,971,977,983,991,997,1009,1013,1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,1087,1091,1093,1097);
var n,k,kol,i,nom,j:longint;
    f:text;


procedure inputdata;
begin
 readln(n,k);
end;

procedure dix(chiclo:longint; var nom:longint);
var l,r,d,min,nn:longint;
begin
 l:=1; r:=184;
 while r-l>1 do
  begin
  d:=pro[(l+r) div 2]; nn:=(l+r) div 2;
  if d>chiclo then r:=nn
              else l:=nn;
  end;
 min:=abs(chiclo-pro[l]); nom:=l;
 if abs(chiclo-pro[r])<min then begin nom:=r; min:=abs(chiclo-pro[l]); end;
 if min=0 then nom:=nom+1;
end;

procedure outputdata(priz:longint);
begin
 if priz=1 then writeln('YES')
           else writeln('NO');
end;

begin
 inputdata; kol:=0; dix(n,nom);
 for i:=nom downto 2 do
  for j:=i downto 2 do
   if (pro[j]+pro[j-1]+1) = pro[i] then inc(kol);
 if kol>=k then outputdata(1)
           else outputdata(0);
end.