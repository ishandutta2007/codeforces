var
    s:array[1..30] of string; n,i:longint; x,y:char;


function have(st:string):boolean;
var nom:longint;
begin
  have:=false;
  for i:=1 to n do
    begin
      nom:=pos(st,s[i]);
      if nom<>0 then begin have:=true; exit; end;
    end;
end;


begin

  readln(n); for i:=1 to n do readln(s[i]);
  for x:='a' to 'z' do
    begin
      if have(x)=false then begin writeln(x); halt; end;
    end;
  for x:='a' to 'z' do
    for y:='a' to 'z' do
      begin
        if have(x+y)=false then begin writeln(x+y); halt; end;
     end;

end.