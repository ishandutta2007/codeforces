program Project31A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, i, j, g: Integer;
  a: array[1..100] of integer;

begin
  Readln(n);
  for i := 1 to n do begin
    read(a[i]);
  end;
  for i := 1 to n do begin
    for j := 1 to n do begin
      for g := 1 to n do begin
        if (i <> j) and (j <> g) and (i <> g) and (a[i] = a[j] + a[g]) then
        begin
          write(i, ' ', j, ' ', g);
          Exit;
        end;
      end;
    end;
  end;
  write(-1);
  readln;
  readln;
end.