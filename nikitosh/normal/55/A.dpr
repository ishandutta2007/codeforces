program Project55A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  a: integer;

function stepen(a: Integer): Boolean;

begin
  Result := true;
  while a <> 1 do begin
    if a mod 2 =1 then
    begin
      Result := False;
      Break;
    end;
    a := a div 2;
  end;
end;

begin
  read(a);
  if stepen(a) then
    Writeln('YES')
  else
    Writeln('NO');
  readln;
  readln;
end.