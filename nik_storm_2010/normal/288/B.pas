const module=1000000007;
var
    f:array[1..8] of longint; used:array[1..8] of boolean; ans,n,k:int64; i:longint;


function can(nom:longint):boolean;
begin
  fillchar(used,sizeof(used),false);
  while true do
    begin
      if nom=1 then exit(true);
      if used[nom]=true then exit(false);
      used[nom]:=true; nom:=f[nom];
    end;
end;


procedure rec(nom:longint);
var i:longint;
begin
  if nom>k then
    begin
      for i:=2 to k do if can(i)=false then exit;
      inc(ans);
    end
      else
    begin
      for i:=1 to k do
        begin
        f[nom]:=i; rec(nom+1);
        end;
    end;
end;


begin

  readln(n,k); ans:=0; rec(2); ans:=ans*k;
  for i:=k+1 to n do ans:=(ans*(n-k)) mod module;
  writeln(ans);

end.