program ProjectB;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  N, k, i, j, a1, a2, a3, a4, a5, a6, x, y, z, maxx, maxy, maxz, l: Integer;
  s, maxt, maxr, maxq, t, r: string;

begin
  //Reset(Input, 'aaa.in');
  //Rewrite(Output, 'aaa.out');
  Readln(N);
  maxx := -1;
  maxy := -1;
  maxz := -1;
  for i := 1 to N do begin
    x := 0;
    y := 0;
    z := 0;
    readln(t);
    r := '';
    for j := 1 to Length(t) do begin
      if (t[j] = ' ') then
      begin
        l := j;
        Break;
      end;
      r := r + t[j];
    end;
    k := StrToInt(r);
    Delete(t, 1, l);
    for j := 1 to k do begin
      Readln(s);
      a1 := StrToInt(s[1]);
      a2 := StrToInt(s[2]);
      a3 := StrToInt(s[4]);
      a4 := StrToInt(s[5]);
      a5 := StrToInt(s[7]);
      a6 := StrToInt(s[8]);
      if (a1 = a2) and (a1 = a3) and (a1 = a4) and (a1 = a5) and (a1 = a6) then
        Inc(x)
      else
      begin
        if (a1 > a2) and (a2 > a3) and (a3 > a4) and (a4 > a5) and (a5 > a6) then
          Inc(y)
        else
          Inc(z);
      end;
    end;
    if (x = maxx) then
      maxt := maxt + ', ' + t;
    if (x > maxx) then
    begin
      maxx := x;
      maxt := '';
      maxt := maxt + t;
    end;
    if (y = maxy) then
      maxr := maxr + ', ' + t;
    if (y > maxy) then
    begin
      maxy := y;
      maxr := '';
      maxr := maxr + t;
    end;
    if (z = maxz) then
      maxq := maxq + ', ' + t;
    if (z > maxz) then
    begin
      maxz := z;
      maxq := '';
      maxq := maxq + t;
    end;
  end;
  Writeln('If you want to call a taxi, you should call: ', maxt, '.');
  Writeln('If you want to order a pizza, you should call: ', maxr, '.');
  Writeln('If you want to go to a cafe with a wonderful girl, you should call: ', maxq, '.');
  readln;
  readln;
end.