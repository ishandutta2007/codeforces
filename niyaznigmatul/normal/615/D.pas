


function mul(a, b, md : longint) : longint;
  begin
    mul := longint(int64(a) * b mod md);
  end;

function modpow(a, b, md : longint) : longint;
var
  res : longint;
  begin
    res := 1;
    while b > 0 do begin
      if (b and 1) = 1 then begin
        res := mul(res, a, md);
      end;
      a := mul(a, a, md);
      b := b shr 1;
    end;
    modpow := res;
  end;

const md = 1000000007;

var
  c, a, pref, suf : array[0 .. 1234567] of longint;
  ans, m, i, pos, f, g, z : longint;

procedure qsort(l, r : longint);
var
  i, j, x, t : longint;
  begin
    if l >= r then exit;
    x := a[random(r - l + 1) + l];
    i := l;
    j := r;
    while i <= j do begin
      while a[i] < x do inc(i);
      while a[j] > x do dec(j);
      if i <= j then begin
        t := a[i];
        a[i] := a[j];
        a[j] := t;
        inc(i);
        dec(j);
      end;
    end;
    qsort(i, r);
    qsort(l, j);
  end;


begin
  read(m);
  for i := 1 to m do begin
    read(a[i]);
  end;
  qsort(1, m);
  pos := 1;
  for i := 1 to m do c[i] := 0;
  for i := 1 to m do begin
    if (a[i] <> a[pos]) then begin
      inc(pos);
      a[pos] := a[i];
    end;
    inc(c[pos]);
  end;
  m := pos;
  pref[0] := 1;
  for i := 1 to m do begin
    pref[i] := mul(pref[i - 1], c[i] + 1, md - 1);
  end;
  suf[m + 1] := 1;
  for i := m downto 1 do begin
    suf[i] := mul(suf[i + 1], c[i] + 1, md - 1);
  end;
  ans := 1;
  for i := 1 to m do begin
    z := mul(pref[i - 1], suf[i + 1], md - 1);
    f := c[i];
    g := c[i] + 1;
    if (f and 1) = 1 then g := g shr 1 else f := f shr 1;
    z := mul(z, f, md - 1);
    z := mul(z, g, md - 1);
    ans := mul(ans, modpow(a[i], z, md), md);
  end;
  writeln(ans);
end.