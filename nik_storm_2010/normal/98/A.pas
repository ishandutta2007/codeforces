type word=string[6];
var
  all:array[1..1000] of word; used:array[1..6] of boolean; a,s:word; ans:longint;


function good(s:word;nom:longint):boolean;
var i:longint; sim:char;
begin
  good:=false;
  for i:=1 to 4 do
  begin
    if all[nom]=s then exit(true); sim:=s[2];
    s[2]:=s[3]; s[3]:=s[4]; s[4]:=s[5]; s[5]:=sim;
  end;
end;


procedure rec(nom:longint);
var i:longint;
begin
  if nom=7 then
  begin
    for i:=1 to ans do
    begin
      if good(a[1]+a[2]+a[3]+a[4]+a[5]+a[6],i) then exit;
      if good(a[2]+a[6]+a[3]+a[1]+a[5]+a[4],i) then exit;
      if good(a[3]+a[2]+a[6]+a[4]+a[1]+a[5],i) then exit;
      if good(a[4]+a[1]+a[3]+a[6]+a[5]+a[2],i) then exit;
      if good(a[5]+a[2]+a[1]+a[4]+a[6]+a[3],i) then exit;
      if good(a[6]+a[4]+a[3]+a[2]+a[5]+a[1],i) then exit;
    end;
    inc(ans); all[ans]:=a;
  end
    else
  begin
    for i:=1 to 6 do if used[i]=false then
    begin
      used[i]:=true; a[nom]:=s[i];
      rec(nom+1);
      used[i]:=false;
    end;
  end;
end;


begin

  readln(s); a:='sample';
  rec(1);
  writeln(ans);

end.