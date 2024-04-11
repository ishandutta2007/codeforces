const bite=64;
var
  a,l,r:array[0..200000] of int64; bor:array[0..10000000,0..1] of int64;
  tek:array[0..bite] of int64; k,n,i:longint; ans,cur:int64;


procedure razlog(c:int64);
begin
  fillchar(tek,sizeof(tek),0);
  while c<>0 do
  begin
    inc(tek[0]); tek[tek[0]]:=c mod 2;
    c:=c div 2;
  end;
end;


procedure insert(c:int64);
var cur,i:longint;
begin
  razlog(c); cur:=0;
  for i:=bite downto 1 do
  begin
    if bor[cur,tek[i]]=0 then begin inc(k); bor[cur,tek[i]]:=k; end;
    cur:=bor[cur,tek[i]];
  end;
end;


procedure find(c:int64;var res:int64);
var cur,nn,i:longint; per:int64;
begin
  razlog(c); cur:=0; res:=0; per:=1;
  for i:=bite downto 1 do
  begin
    nn:=1 xor tek[i];
    if bor[cur,nn]<>0 then begin res:=res+(per shl (i-1)); cur:=bor[cur,nn]; end
                      else begin cur:=bor[cur,1-nn]; end;
  end;
end;



begin

  readln(n); for i:=1 to n do read(a[i]);
  ans:=0; k:=0;
  for i:=1 to n do l[i]:=l[i-1] xor a[i];
  for i:=n downto 1 do r[i]:=r[i+1] xor a[i];
  insert(r[n+1]);
  for i:=n downto 0 do
  begin
    find(l[i],cur); insert(r[i]);
    if cur>ans then ans:=cur;
  end;
  writeln(ans);

end.