const
  md=round(1e9)+7;
var
  dp:array[0..10,0..10,0..1] of int64;
  cnt,res,a:array[0..10] of int64;
  ans,m,i,j,k,x,next,ni,nx,nj:longint;

procedure solve(nom,k,sum:longint;num:int64);
var
  i:longint;
begin
  if (nom=7) then
  begin
    res[k]:=res[k]+num;
    if (res[k]>=md) then res[k]:=res[k]-md;
    exit;
  end;
  for i:=0 to 9 do if (cnt[i]<>0) then
  begin
    if (sum+i>=k) then break;
    dec(cnt[i]);
    solve(nom+1,k,sum+i,(num*(cnt[i]+1)) mod md);
    inc(cnt[i]);
  end;
end;

begin
  readln(m);
  for k:=1 to 10 do
  begin
    a[k]:=m mod 10;
    m:=m div 10;
    if (m=0) then break;
  end;
  for i:=1 to k do
  begin
    j:=k-i+1;
    if (i>j) then break;
    x:=a[i]; a[i]:=a[j]; a[j]:=x;
  end;
  dp[0,0,0]:=1;
  for i:=0 to k-1 do for j:=0 to k do for x:=0 to 1 do
  begin
    if (dp[i,j,x]=0) then continue;
    ni:=i+1;
    for next:=0 to 9 do
    begin
      if (x=1) then nx:=1 else
      begin
        if (next<a[ni]) then nx:=1;
        if (next=a[ni]) then nx:=0;
        if (next>a[ni]) then continue;
      end;
      nj:=j;
      if (next=4) or (next=7) then inc(nj);
      dp[ni,nj,nx]:=dp[ni,nj,nx]+dp[i,j,x];
      if (dp[ni,nj,nx]>=md) then dp[ni,nj,nx]:=dp[ni,nj,nx]-md;
    end;
  end;
  for j:=0 to k do for x:=0 to 1 do cnt[j]:=(cnt[j]+dp[k,j,x]) mod md;
  dec(cnt[0]);
  for i:=0 to 9 do
  begin
    if (cnt[i]=0) then continue;
    dec(cnt[i]);
    solve(1,i,0,1);
    inc(cnt[i]);
  end;
  for i:=0 to 9 do ans:=(ans+cnt[i]*res[i]) mod md;
  writeln(ans);
end.