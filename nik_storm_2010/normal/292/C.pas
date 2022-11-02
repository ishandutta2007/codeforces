type byte=integer;
var
    ans:array[0..10000,1..4] of integer; kol:array[0..255,0..4] of byte; tek,num:array[0..12] of byte;
      maybe,used:array[0..255] of boolean; have:array[0..9] of longint; k,n,c,i:longint;


function good(tek:longint):boolean;
var s:shortstring; c,i:longint;
begin
  str(tek,s); kol[tek,0]:=length(s);
  for i:=1 to kol[tek,0] do
    begin
      val(s[i],c); kol[tek,i]:=c;
      if used[c]=false then exit(false);
    end;
  good:=true;
end;


procedure check(leng:longint);
var pred,res,i:longint;
begin
  pred:=(num[0]-leng) div 2;
  for i:=1 to pred do
    if num[leng+i]<>num[num[0]-i+1] then exit;
  res:=0;
  for i:=leng downto 1 do res:=res*10+num[i];
  if res>255 then exit;
  inc(k);
  ans[k,1]:=tek[1]; ans[k,2]:=tek[2]; ans[k,3]:=tek[3]; ans[k,4]:=res;
end;


procedure rec(nom:longint);
var i,j:longint;
begin
  if nom=4 then
    begin
      for i:=0 to 9 do if (used[i]) and (have[i]=0) then exit;
      check(1);
      if num[2]<>0 then check(2);
      if num[3]<>0 then check(3);
    end
      else
    begin
      for i:=0 to 255 do
        if maybe[i] then
        begin
          tek[nom]:=i;
          for j:=1 to kol[i,0] do
            begin
              inc(have[kol[i,j]]); inc(num[0]);
              num[num[0]]:=kol[i,j];
            end;
          rec(nom+1);
          for j:=1 to kol[i,0] do
            begin
              dec(have[kol[i,j]]); dec(num[0]);
            end;
        end;
    end;
end;


begin

  readln(n); ans[0,4]:=-1;
  for i:=1 to n do
    begin
      read(c); used[c]:=true;
    end;
  for i:=0 to 255 do
    if good(i) then maybe[i]:=true;
  k:=0; rec(1);
  writeln(k);
  for i:=1 to k do writeln(ans[i,1],'.',ans[i,2],'.',ans[i,3],'.',ans[i,4]);

end.