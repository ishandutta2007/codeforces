const
  l=100;
type
  dp=record
    x,y,z,num:longint;
    used:boolean;
  end;
var
  f:array[0..l,0..l,0..l] of dp;
  go:array[0..l,'A'..'Z'] of longint;
  max,d1,d2,dv,i,j,k,x,y,z:longint;
  p:array[0..l] of longint;
  ans,s1,s2,v:string;
  c:char;

procedure kmp;
var
  k,i:longint;
begin
  k:=0;
  for i:=2 to dv do
  begin
    while (k>0) and (v[k+1]<>v[i]) do k:=p[k];
    if (v[k+1]=v[i]) then inc(k);
    p[i]:=k;
  end;
end;

begin
  readln(s1);
  readln(s2);
  readln(v);
  d1:=length(s1);
  d2:=length(s2);
  dv:=length(v);
  kmp;
  for i:=0 to dv-1 do for c:='A' to 'Z' do if (v[i+1]=c) then go[i,c]:=i+1 else go[i,c]:=go[p[i],c];
  for i:=0 to d1 do for j:=0 to d2 do for k:=0 to dv-1 do
  begin
    if (i*j=0) and (k>0) then continue;
    if (i<>d1) and (j<>d2) and (s1[i+1]=s2[j+1]) and (f[i+1,j+1,go[k,s1[i+1]]].num<f[i,j,k].num+1) then
    begin
      f[i+1,j+1,go[k,s1[i+1]]].num:=f[i,j,k].num+1;
      f[i+1,j+1,go[k,s1[i+1]]].x:=i;
      f[i+1,j+1,go[k,s1[i+1]]].y:=j;
      f[i+1,j+1,go[k,s1[i+1]]].z:=k;
      f[i+1,j+1,go[k,s1[i+1]]].used:=true;
    end;
    if (i<>d1) and (f[i+1,j,k].num<f[i,j,k].num) then
    begin
      f[i+1,j,k].num:=f[i,j,k].num;
      f[i+1,j,k].x:=i;
      f[i+1,j,k].y:=j;
      f[i+1,j,k].z:=k;
      f[i+1,j,k].used:=false;
    end;
    if (j<>d2) and (f[i,j+1,k].num<f[i,j,k].num) then
    begin
      f[i,j+1,k].num:=f[i,j,k].num;
      f[i,j+1,k].x:=i;
      f[i,j+1,k].y:=j;
      f[i,j+1,k].z:=k;
      f[i,j+1,k].used:=false;
    end;
  end;
  max:=0;
  for x:=0 to dv-1 do if (max<f[d1,d2,x].num) then
  begin
    max:=f[d1,d2,x].num;
    k:=x;
  end;
  if (max=0) then writeln(0) else
  begin
    i:=d1;
    j:=d2;
    while (i>0) and (j>0) do
    begin
      if (f[i,j,k].used) then ans:=s1[i]+ans;
      x:=f[i,j,k].x;
      y:=f[i,j,k].y;
      z:=f[i,j,k].z;
      i:=x;
      j:=y;
      k:=z;
    end;
    writeln(ans);
  end;
end.