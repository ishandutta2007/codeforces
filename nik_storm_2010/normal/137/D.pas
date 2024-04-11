uses
  math;
const
  oo=maxlongint;
  lim=500;
var
  f,pal,prev:array[0..lim,0..lim] of longint;
  ans,k,n,i,l,r,p:longint;
  s,res:ansistring;

procedure add(l,r:longint);
var
  i,j:longint;
begin
  i:=l; j:=r;
  while (i<=j) do
  begin
    if (s[i]<>s[j]) then s[i]:=s[j];
    inc(i); dec(j);
  end;
  for i:=r downto l do res:=s[i]+res;
  res:='+'+res;
end;

begin
  for l:=0 to lim do for r:=0 to lim do f[l,r]:=oo;
  readln(s);
  readln(k);
  n:=length(s);
  for i:=2 to n do for l:=1 to n-i+1 do
  begin
    r:=l+i-1;
    pal[l,r]:=pal[l+1,r-1];
    if (s[l]<>s[r]) then inc(pal[l,r]);
  end;
  f[0,0]:=0;
  for r:=1 to n do for i:=1 to k do for l:=r-1 downto 0 do
  begin
    if (f[l,i-1]=oo) then continue;
    if (f[r,i]>f[l,i-1]+pal[l+1,r]) then
    begin
      f[r,i]:=f[l,i-1]+pal[l+1,r];
      prev[r,i]:=l;
    end;
    f[r,i]:=min(f[r,i],f[l,i-1]+pal[l+1,r]);
  end;
  ans:=oo;
  for i:=1 to k do if (ans>f[n,i]) then begin ans:=f[n,i]; p:=i; end;
  res:=''; r:=n;
  for i:=p downto 1 do
  begin
    add(prev[r,i]+1,r);
    r:=prev[r,i];
  end;
  delete(res,1,1);
  writeln(ans);
  writeln(res);
end.